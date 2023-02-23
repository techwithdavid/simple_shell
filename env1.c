#include "shell.h"

/**
 * link_count - counts number of nodes in linked list
 * @head: pointer to head of linked list
 *
 * Return: number of nodes
 */
unsigned int link_count(env_t *head)
{
	env_t *tmp;
	unsigned int count;

	tmp = head;
	count = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}

	return (count);
}

/**
 * env_list - creates a linked list of all environ variables
 *
 * Return: head (pointer to first node of linked list of environ variables)
 */
env_t *env_list(void)
{
	int i;
	env_t *head;
	char **variable;

	head = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		variable = separate_string(environ[i]);
		if (add_node_env(&head, variable[0], variable[1]) == NULL)
			return (NULL);
		free(variable[0]);
		free(variable[1]);
		free(variable);
	}

	return (head);
}

/**
 * link_to_dpointer - converts linked list to double pointer
 * @head: head pointer to head of linked list
 *
 * Return: array of pointers, pointing to strings
 */
char **link_to_dpointer(env_t *head)
{
	int i;
	unsigned int count, len1, len2, lennew;
	char **dpointer, *var, *val, *new_val;
	env_t *tmp;

	count = link_count(head);
	dpointer = malloc(sizeof(char *) * (count + 1));

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		var = tmp->var;
		val = tmp->val;
		len1 = _strlen(var);
		len2 = _strlen(val);

		lennew = len1 + len2 + 2;
		new_val = safe_malloc(lennew * sizeof(char));

		_strncat(new_val, var, len1);
		_strncat(new_val, "=", 1);
		_strncat(new_val, val, len2);
		dpointer[i] = new_val;
		tmp = tmp->next;
		i++;
	}
	dpointer[i] = NULL;

	return (dpointer);
}
