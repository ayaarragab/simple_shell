#include "main.h"
/**
 * 
*/
char *trim(char *command)
{
	char *end;

	while (isspace((unsigned char)*command))
		command++;
	if (*command == 0)
		return (command);
	
	end = command + strlen(command) - 1;
	while (end > command && isspace((unsigned char)*end))
        end--;
	*(end + 1) = '\0';
	return (command);
}
