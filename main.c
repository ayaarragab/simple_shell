#include "main.h"
/**
 * make_array_of_strings - func
 * @command: command entered
 * Return: array of strings
*/
char **make_array_of_strings(char *command)
{
	char *token = malloc(BUFF_SIZE);
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	int num_tokns = 0, i, j = 0;

	token = _strtok(command, " ");
	if (tokens == NULL || token == NULL)
		return (NULL);
	while (token != NULL)
	{
		tokens[num_tokns] = malloc(strlen(token) + 1);
		if (tokens[num_tokns] == NULL)
		{
			for (i = 0; i < num_tokns; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		strcpy(tokens[num_tokns], token);
		num_tokns++;
		token = _strtok(NULL, " ");
	}
	while (j < num_tokns)
	{
		if (j == num_tokns - 1)
		{
			tokens[j][strlen(tokens[j]) - 1] = '\0';
			break;
		}
		j++;
	}
	tokens[num_tokns] = NULL;
	return (tokens);
}
/**
 * main - main function
 * @argc: length of vector array
 * @argv: vector array
 * @env: environment variables
 * Return: 0 in success, -1 in error
*/
int main(int argc, char **argv, char **env)
{
	char *command_buffer, *shell_path = malloc(BUFF_SIZE);
	size_t size = BUFF_SIZE, i;
	char **array_tokens;
	(void)argc;
	(void)argv;

	command_buffer = malloc(BUFF_SIZE * sizeof(char));
	getcwd(shell_path, BUFF_SIZE);
	strcat(shell_path, "/shell");
	_setenv("shell", shell_path, 1);
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (_getline(&command_buffer, &size, stdin) == -1)
			break;
		array_tokens = make_array_of_strings(command_buffer);
		for (i = 0; array_tokens[i] != NULL; i++)
			continue;
		execute_function(array_tokens, i, env);
	}
	free(shell_path);
	free(command_buffer);
	return (0);
}
