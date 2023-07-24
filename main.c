#include "main.h"
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
	char *token = malloc(BUFF_SIZE);
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	int num_tokns = 0, i;

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
	char *command_buffer, *trimmed;
	char **environ;
	size_t size = BUFF_SIZE, i;
	char **array_tokens;
	(void)argc;
	(void)argv;
	command_buffer = malloc(BUFSIZ * sizeof(char));
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (_getline(&command_buffer, &size, stdin) == -1)
			break;
		if (check_if_all_spaces(command_buffer) == 0)
			continue;
		else
		{
			trimmed = trim(command_buffer);
			if (trimmed == NULL)
				continue;
			if (strcmp(trimmed, "env\n") == 0)
			{
				environ = env;
				while (*environ != NULL)
				{
					printf("%s\n", *environ);
					environ++;
				}
				continue;
			}
			else if (strcmp(trimmed, "exit\n") == 0)
				exit_command();
			array_tokens = make_array_of_strings(trimmed);
			for (i = 0; array_tokens[i] != NULL; i++)
				continue;
			execute_function(array_tokens, i, env);
		}
	}
	free(command_buffer);
	return (0);
}
