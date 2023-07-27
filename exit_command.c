#include "main.h"
/**
 * handle_validated - specfies if -ve or string or +ve
 * @str: str after exit
 * Return: false or true
*/
int handle_validated(char *str)
{
	int i = 0;

	if (str[0] == '-')
		return (0);
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
		return (1);
}
/**
 * exit_command - exit shell with a specific status
 * @command: The exit status to set
 * Return: exit value
 */
int exit_command(char *command)
{
	char *status_str = strchr(command, ' ');
	int status_number;

	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(0);
	}
	if (status_str != NULL)
	{
		status_str++;
		if (handle_validated(status_str))
			status_number = atoi(status_str);
		else
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", status_str);
			exit(2);
		}
		exit(status_number);
	}
	free(command);
	return (0);
}
