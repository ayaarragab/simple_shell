#include "main.h"
/**
 * cd_command - Change the current directory and update environment variables.
 * @directory: The directory to change to. If NULL, changes to $HOME.
 * Return: nothing
 */

void cd_command(char **directory)
{
	char *go_dir;
	char cwd[MAX_PATH_LENGTH];
	char *prev_cwd = getenv("OLDPWD");

	if (prev_cwd  == NULL)
	{
		perror("getenv");
		return;
	}
	if (directory[1] == NULL)
	{
		go_dir = getenv("HOME");
		if (go_dir == NULL)
		{
			fprintf(stderr, "cd: could not find $HOME\n");
			return;
		}
	}
	else if (strcmp(directory[1], "-") == 0)
	{
		go_dir = prev_cwd;
	}
	else
	{
		go_dir = directory[1];
	}
	if (chdir(go_dir) == -1)
	{
		perror("chdir");
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", cwd, 1);
	printf("%s\n", cwd);
}

