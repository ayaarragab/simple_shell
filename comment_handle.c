#include "main.h"
/**
 * comment_handle- deletes comments from the input
 * @command: input string
 * Return: command without comments
 */
void comment_handle(char *command)
{
	int i = 0;

	for(i = 0; command[i] != '\0'; i++)
	{
		if (command[i - 1] == ' ' && command[i] == '#')
		{
			command[i] = '\0';
			break;
		}
	}
}
