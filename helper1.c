#include "shell.h"

/**
 * help_alias - help function to explain how the associated function works
 */
void help_alias(void)
{
	_puts("\nUsage: $ alias [NAME]=[VALUE]");
	_puts("\tDefine or display aliases, in the form:");
	_puts("\n\talias [NAME]=[VALUE]");
}

/**
 * help_cd - help function to explain how the associated function works
 */
void help_cd(void)
{
	_puts("\nUsage: $ cd");
	_puts("\tChange the shell working directory.");
}

/**
 * help_env - help function to explain how the associated function works
 */
void help_env(void)
{
	_puts("\nUsage: $ env");
	_puts("\tDisplay all environmental variables, in the form:");
	_puts("\n\t[NAME]=[VALUE]");
}

/**
 * help_exit - help function to explain how the associated function works
 */
void help_exit(void)
{
	_puts("\nUsage: $ exit");
	_puts("\tExit the shell.");
}

/**
 * help_help - help function to explain how the associated function works
 */
void help_help(void)
{
	_puts("\nUsage: $ help [command]");
	_puts("\tDisplay information about builtin commands.");
}
