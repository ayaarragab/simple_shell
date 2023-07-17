#include "main.h"
/**
 * main - main function
 * Return: 0 in success, -1 in error
*/
int main(void)
{
	char *command_buffer;
	size_t size = BUFF_SIZE;
	char *token;
	token = malloc(BUFF_SIZE);
	command_buffer = malloc(BUFF_SIZE * sizeof(char));
	while (1)
	{
		printf("$");
		fflush(stdout);
		if (_getline(&command_buffer, &size, stdin) == -1)
			break;
		/*execute_function(command_buffer);*/
	}
	free(token);
	free(command_buffer);
	return (0);
}
