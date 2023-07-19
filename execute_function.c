#include "main.h"
/**
 * execute_function - excute based on a command
 * @array_tokens: array of tokens
 * @number_of_tokens: n_tokns
 * @env: environmet variables
 * Return: nothing
*/
void execute_function(char **array_tokens, int number_of_tokens, char **env)
{
	pid_t pid;

	array_tokens[number_of_tokens] = NULL;
	pid = fork();
	if (pid  < 0)
	{
		fprintf(stderr, "./shell: No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(array_tokens[0], array_tokens, env) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
}
