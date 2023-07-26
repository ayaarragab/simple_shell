#include "main.h"
/**
 * cd - changes directory
 * @command: command 2d
 * Return: nothing
*/
void cd(char **command)
{
	int i, result;
	struct stat info;
	char *path, new_pwd[1024];

	i = 0;
	while (command[i])
		i++;
	if (i == 1)
		return;
	else if (i == 2)
	{
		path = command[1];
		result = stat(path, &info);
		if (result == 0 && S_ISDIR(info.st_mode))
		{
			chdir(path);
			if (getcwd(new_pwd, sizeof(new_pwd)) != NULL)
			{
				if (setenv("PWD", new_pwd, 1) != 0)
				{
					free_2d(command);
					return;
				}
			}
		}
		else
			printf("Directory does not exist.\n");
	}
}

