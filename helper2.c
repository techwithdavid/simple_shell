#include "shell.h"

/**
 * help_history - help function to explain how the associated function works
 */
void help_history(void)
{
	_puts("\nUsage: $ history");
	_puts("Display the history list.");
}

/**
 * help_setenv - help function to explain how the associated function works
 */
void help_setenv(void)
{
	_puts("\nUsage: $ setenv [NAME] [VALUE]");
	_puts("\tSets a new environmental variable");
}

/**
 * help_unsetenv - help function to explain how the associated function works
 */
void help_unsetenv(void)
{
	_puts("\nUsage: $ unsetenv [NAME]");
	_puts("\tUnsets a saved environmental variable");
}
