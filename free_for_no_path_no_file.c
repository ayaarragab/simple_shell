#include "main.h"
/**
 * free_all_then_exit - solve leaks
 * @command: command_buf
 * @array_token: command line argumnets
 * @array_paths: arry paths
*/
void free_all_then_exit(char **array_token, char **array_paths, char *command)
{
	free_2d(array_paths);
	free_2d(array_token);
	free(command);
	exit(2);
}

