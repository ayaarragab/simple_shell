#include "main.h"
/**
 * exit_command_2 - exit shell with a specific status
 * @status: The exit status to set
 * @command: command to be freed
 * Return: nothing
 */
void exit_command_2(int status, char *command)
{
	free(command);
	exit(status);
}
/**
 * check_if_all_spaces - checks if the line contain only spaces
 * @command: command str
 * Return: 0 if all spaces 1 if not all
*/
int check_if_all_spaces(char *command)
{
	int cntr;
	static size_t sp;

	sp = 0;
	cntr = 0;
	if (command[cntr] == ' ')
	{
		while (command[sp])
			if (isspace((unsigned char)command[sp]))
				sp++;
			else
				break;
		cntr++;
	}
	if (sp == strlen(command))
		return (0);
	return (1);
}
/**
 * make_array_of_strings - func
 * @command: command entered
 * Return: array of strings
*/
char **make_array_of_strings(char *command)
{
	char *token;
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	int num_tokns = 0, i;

	token = _strtok(command, " ");

	if (tokens == NULL || token == NULL)
		return (NULL);
	while (token != NULL)
	{
		tokens[num_tokns] = strdup(token);
		if (tokens[num_tokns] == NULL)
		{
			for (i = 0; i < num_tokns; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		num_tokns++;
		token = _strtok(NULL, " ");
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
	char *command_buffer = malloc(BUFSIZ * sizeof(char)), *trimmed, **array_tokens;
	size_t size = BUFF_SIZE, i;
	(void)argc;
	(void)argv;
	while (1)
	{
		fflush(stdout);
		if (_getline(&command_buffer, &size, stdin) == -1)
			break;
		if (check_if_all_spaces(command_buffer) == 0)
			continue;
		trimmed = trim(command_buffer);
		if (trimmed == NULL)
		{
			free(command_buffer);
			continue;
		}
		if (strcmp(trimmed, "env") == 0)
		{
			envv(env, command_buffer);
			continue;
		}
		else if (strcmp(trimmed, "exit") == 0)
			exit_command_2(0, command_buffer);
		array_tokens = make_array_of_strings(trimmed);
		if (array_tokens != NULL)
		{
		for (i = 0; array_tokens[i] != NULL; i++)
			continue;
		if (strcmp(array_tokens[0], "cd") == 0)
		{
			cd(array_tokens);
			continue;
		}
		execute_function(array_tokens, i, env);
		free_2d(array_tokens);
		}
	}
	free(command_buffer);
	return (0);
}
