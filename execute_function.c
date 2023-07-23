#include "main.h"
/**
 * error_behave - to minimize lines of execute function
 * Return: nothing
*/
void error_behave(void)
{
	fprintf(stderr, "./shell: No such file or directory\n");
	exit(EXIT_FAILURE);
}
/**
 * check_for_correct_path - checks for correct path
 * @argv: command line arguments
 * @array_paths: array_of_paths
 * Return: edited argv with correct path
*/
char *check_for_correct_path(char **argv, char **array_paths)
{
	char **edited_argv = argv;
	char *concatenated_path;
	int i;

	for (i = 0; array_paths[i] != NULL ; i++)
	{
		concatenated_path = strcat(array_paths[i], "/");
		strcat(concatenated_path, edited_argv[0]);
		if (access(concatenated_path, F_OK) == 0)
			return (concatenated_path);
	}
	return (NULL);
}
/**
 * PATH_directories - function to use PATH
 * @env: environment variables
 * Return: string containing all paths
*/
char *PATH_directories(char **env)
{
	while (*env != NULL)
	{
		if (strncmp(*env, "PATH", 4) == 0)
			return (strchr(*env, '=') + 1);
		env++;
	}
	return (NULL);
}
/**
 * execute_function - excute based on a command
 * @array_tokens: array of tokens
 * @number_of_tokens: number of tokens
 * @env: environment variables
 * Return: nothing
*/
void execute_function(char **array_tokens, int number_of_tokens, char **env)
{
	pid_t pid;
	char *PATH;
	char **array_of_paths;

	PATH = PATH_directories(env);
	array_of_paths = make_paths_seperately(PATH);
	array_tokens[number_of_tokens] = NULL;
	if (array_tokens[0][0] == '/')
	{
		pid = fork();
		if (pid  < 0)
			error_behave();
		else if (pid == 0)
		{
			if (execve(array_tokens[0], array_tokens, env) == -1)
				error_behave();
		}
		else
			wait(NULL);
	}
	else
	{
		if (check_for_correct_path(array_tokens, array_of_paths) != NULL)
			pid = fork();
		if (pid  < 0)
			error_behave();
		else if (pid == 0)
		{
			if (execve(check_for_correct_path(array_tokens, array_of_paths),
			array_tokens, env) == -1)
				error_behave();
		}
		else
			wait(NULL);
	}
}
