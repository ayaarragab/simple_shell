#include "main.h"
/**
 * trim - delete the spaces around string
 * @command: command
 * Return: command
*/
char *trim(char *command)
{
	char *end;

	while (isspace((unsigned char)*command))
		command++;
	if (*command == 0)
		return (command);
	end = command + strlen(command) - 1;
	while (end > command && isspace((unsigned char)*end))
		end--;
	*(end + 1) = '\0';
	return (command);
}
