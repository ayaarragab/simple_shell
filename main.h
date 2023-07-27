#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <ctype.h>
ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin);
char *_strtok(char *string, const char *delim);
/**
 * struct tokens_list - tokens linked list
 * @token: token
 * @next: next pointer to node
*/
typedef struct tokens_list
{
	char *token;
	struct tokens_list *next;
} token_node;
void execute_function(char **array_tokens, int number_of_tokens, char **env, char *command);
void free_all_then_exit(char **array_token, char **array_paths, char *command);
int _setenv(const char *name, const char *value, int overwrite);
void exit_command(int status);
char **make_paths_seperately(char *paths);
char *trim(char *str);
void free_2d(char **arr_2D);
void envv(char **envi, char *command);
void cd(char **command);
#define BUFF_SIZE 1024
#include "main.h"
#endif
