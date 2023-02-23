#include "shell.h"

/**
 * process_execute_core - this is the core execution function
 * @arginv: arg inventory
 *
 * Return: 0
 */
pid_t process_execute_core(arg_inventory_t *arginv)
{
	unsigned int i;
	ptree_t *ptree;

	for (i = 0; i < arginv->pipeline.processesN; i++)
	{
		ptree = arginv->pipeline.processes[i].ptree;
		arginv->commands = ptree->strings;
		ptree->stringsN += expand_alias(arginv);
		ptree->strings = arginv->commands;
		arginv->pipeline.processes[i].pid = execute(arginv);
	}
	return (arginv->pipeline.processes[arginv->pipeline.processesN - 1].pid);
}

/**
 * process_execute_tree - this executes ptree
 * @arginv: arg inventory
 * @ptree: the parsing tree
 * @depth: the depth of parsing tree
 *
 * Return: the last pid
 */
pid_t process_execute_tree(arg_inventory_t *arginv, ptree_t *ptree,
						  unsigned int depth)
{
	int status = 0, id, execute = 1;
	pid_t last_pid = -1;

	if (!ptree)
		return (last_pid);
	id = ptree->token_id;
	if (id == TOKEN_STRING || id == TOKEN_PIPE || is_redirection(id))
	{ /* execute pipeline */
		init_pipeline(&arginv->pipeline, ptree);
		last_pid = process_execute_core(arginv);
		delete_pipeline(&arginv->pipeline);
		return (last_pid);
	} /* recursive call on each child */
	if (ptree->left)
	{
		last_pid = process_execute_tree(arginv, ptree->left, depth + 1);
		if (id != TOKEN_BACKGROUND)
		{ /* wait for the child */
			waitpid(last_pid, &status, 0);
			status = WEXITSTATUS(status);
		}
		else
			arginv->n_bg_jobs++, arginv->last_bg_pid = last_pid;
		switch (status)
		{
		case 1:
			arginv->exit_status = 127;
			break;
		default:
			arginv->exit_status = status;
			break;
		}
		if ((id == TOKEN_AND && status) || (id == TOKEN_OR && !status))
			execute = 0;
		if (execute)
			last_pid = process_execute_tree(arginv, ptree->right, depth + 1);
	}
	return (last_pid);
}

/**
 * process_execute - executes background process
 * @arginv: arginv
 *
 * Return: 0 or exit
 */
int process_execute(arg_inventory_t *arginv)
{
	pid_t last_pid;
	int status = 0;

	arginv->n_bg_jobs = 0;

	last_pid = process_execute_tree(arginv, arginv->parser.tree, 0);

	if (last_pid != -1)
	{
		if (arginv->parser.tree->token_id != TOKEN_BACKGROUND)
		{
			waitpid(last_pid, &status, 0);
			status = WEXITSTATUS(status);
		}
		else
		{
			arginv->n_bg_jobs++;
			arginv->last_bg_pid = last_pid;
		}
		switch (status)
		{
		case 1:
			arginv->exit_status = 127;
			break;
		default:
			arginv->exit_status = status;
			break;
		}
	}
	return (0);
}
