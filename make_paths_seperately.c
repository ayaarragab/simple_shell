#include "main.h"
/*
 * make_paths_seperately - to check spaces between strings
 *
 */
char **make_paths_seperately(char *paths)
{
	char *token;
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	int num_tokens = 0, i;
	char paths_copy[BUFF_SIZE];

	strcpy(paths_copy, paths);
	token = _strtok(paths_copy, ":");
	if (tokens == NULL || token == NULL)
		return (NULL);
	while (token != NULL)
	{
		tokens[num_tokens] = strdup(token);
		if (tokens[num_tokens] == NULL)
		{
			for (i = 0; i < num_tokens; i++)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		num_tokens++;
		token = _strtok(NULL, ":");
	}
	tokens[num_tokens] = NULL;
	return (tokens);
}
