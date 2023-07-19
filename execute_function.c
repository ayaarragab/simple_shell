#include "main.h"
/**
 * execute_function - excute based on a command
 * @array_tokens: array of tokens
 * Return: nothing
*/
void execute_function(char **array_tokens)
{
	char *command = NULL;
	pid_t pid = fork();

	command = array_tokens[0];
	command[strlen(command) - 1] = '\0';
	if (pid  < 0)
	{
		fprintf(stderr, "./shell: No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(array_tokens[0], array_tokens, 0) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
