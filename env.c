#include "main.h"
/**
 * envv - env
 * @command: command
 * @envi: env
 * Return: nothing
*/
void envv(char **envi, char *command)
{
	while (*envi != NULL)
	{
		printf("%s\n", *envi);
		envi++;
	}
	free(command);
}
