#include "main.h"
void envv(char **envi, char *command)
{
	while (*envi != NULL)
	{
		printf("%s\n", *envi);
		envi++;
	}
	free(command);
}
