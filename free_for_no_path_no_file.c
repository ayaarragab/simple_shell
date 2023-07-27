#include "main.h"
/**
 * free_all_then_exit - solve leaks
 * @command: command_buf
 * @array_token: command line argumnets
 * @array_paths: arry paths
*/
void free_all_then_exit(char **array_token, char **array_paths, char *command)
{
	if (array_token != NULL)
		free_2d(array_token);
	if (array_paths != NULL)
		free_2d(array_paths);
	if (command != NULL)
		free(command);
	exit(2);
}

