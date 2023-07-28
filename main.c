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
 * check_if_all_spaces - checks if the line contains only spaces
 * @command: command str
 * Return: 0 if all spaces, 1 if not all
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
 * Return: 0 on success, -1 on error
 */
int main(int argc, char **argv, char **env)
{
	char *commandbuf = malloc(BUFSIZ * sizeof(char)), *trimmed, **array_token;
	size_t size = BUFF_SIZE, i;
	(void)argc;
	(void)argv;

	while (1)
	{
		fflush(stdout);
		if (_getline(&commandbuf, &size, stdin) == -1)
			exit_command_2(0, commandbuf);
		if (check_if_all_spaces(commandbuf) == 0 || commandbuf[0] == '#')
			continue;
		comment_handle(commandbuf);
		trimmed = trim(commandbuf);
		if (trimmed == NULL)
		{
			free(commandbuf);
			continue;
		}
		if (strcmp(trimmed, "env") == 0)
		{
			envv(env, commandbuf);
			continue;
		}
		else if (strncmp(trimmed, "exit", 4) == 0)
			exit_command(commandbuf);

		array_token = make_array_of_strings(trimmed);

		if (array_token != NULL)
		{
			for (i = 0; array_token[i] != NULL; i++)
				continue;
			execute_function(array_token, i, env, commandbuf);
			free_2d(array_token);
		}
	}

	free(commandbuf);
	return (0);
}

