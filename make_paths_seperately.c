#include "main.h"
char **make_paths_seperately(char *paths)
{
	char *token;
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	int num_tokens = 0, i;
	char *paths_copy;

	paths_copy = strdup(paths);
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
			free(paths_copy);
			return (NULL);
		}
		num_tokens++;
		token = _strtok(NULL, ":");
	}
	tokens[num_tokens] = NULL;
	free(paths_copy);
	return (tokens);
}
