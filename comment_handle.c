#include "main.h"
/**
 * comment_handle- deletes comments from the input
 * @command: input string
 * Return: command without comments
 */
void comment_handle(char *command)
{
	int i;

	for (i = 1; command[i] != '\0'; i++)
	{
		if (isspace(command[i - 1]) && command[i] == '#')
		{
			command[i] = '\0';
			break;
		}
	}
}

