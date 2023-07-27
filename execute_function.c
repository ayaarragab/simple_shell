#include "main.h"
/**
 * error_behave - to minimize lines of execute function
 * @argv: command line arguments
 * Return: nothing
*/
void error_behave(char **argv)
{
	int i = 0;

	while (argv[i])
	{
	fprintf(stderr, "./hsh: 1: %s: not found\n", argv[i]);
	i++;
	}
	free_2d(argv);
	exit_command(127);
}
/**
 * check_for_correct_path - checks for correct path
 * @argv: command line arguments
 * @array_paths: array_of_paths
 * Return: edited argv with correct path
*/
char *check_for_correct_path(char **argv, char **array_paths)
{
	char *concatenated_path;
	int i;
	size_t concat_size;

	for (i = 0; array_paths[i] != NULL; i++)
	{
		concat_size = strlen(array_paths[i]) + strlen("/") + strlen(argv[0]) + 1;
		concatenated_path = malloc(concat_size);
		if (concatenated_path == NULL)
			return (NULL);
		strcpy(concatenated_path, array_paths[i]);
		strcat(concatenated_path, "/");
		strcat(concatenated_path, argv[0]);
		if (access(concatenated_path, F_OK) == 0)
			return (concatenated_path);
		free(concatenated_path);
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
 * is_command - checks if entered text is a command
 * @argv: atgv
 * @array_of_paths: array of paths
 * Return: 1 or -1 or 0
*/
int is_command(char **argv, char **array_of_paths)
{
	char *con_path = check_for_correct_path(argv, array_of_paths);

	if (argv[0] == NULL)
		return (0);
	if (access(argv[0], F_OK) == 0)
		return (1);
	else if (con_path)
	{
		free(con_path);
		return (1);
	}
	return (0);
}
/**
 * execute_function - excute based on a command
 * @array_tokens: array of tokens
 * @number_of_tokens: number of tokens
 * @env: environment variables
 * Return: nothing
*/
void execute_function(char **array_tokens, int number_of_tokens, char **env, char *command)
{
	pid_t pid = 1;
	char *PATH, **array_of_paths, *con_path;

	PATH = PATH_directories(env);
	(void)command;
	array_of_paths = make_paths_seperately(PATH);
	array_tokens[number_of_tokens] = NULL;
	if (is_command(array_tokens, array_of_paths))
	{
		pid = fork();
		if (pid == 0)
		{
		if (array_tokens[0][0] == '/' || array_tokens[0][0] == '.')
		{
			if (execve(array_tokens[0], array_tokens, env) == -1)
				error_behave(array_tokens);
		}
		else
		{
			con_path = check_for_correct_path(array_tokens, array_of_paths);
			if (execve(con_path, array_tokens, env) == -1)
				error_behave(array_tokens);
		}
		}
		else if (pid < 0)
			error_behave(array_tokens);
		else
		{
			int status, es;

			if (waitpid(pid, &status, 0) == -1)
				exit_command(EXIT_FAILURE);
			es = WEXITSTATUS(status);
			if (es == 2)
				free_all_then_exit(array_tokens, array_of_paths, command);
		}
	}
	free_2d(array_of_paths);
}
