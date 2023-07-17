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

ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin);
char *_strtok(char *string, const char *delim);
/**
 * tokens_list - tokens linked list
 * @token: token
 * @next: next pointer to node
*/
typedef struct tokens_list{
    char *token;
    struct tokens_list* next;
}token_node;
void execute_function(char *command);
#define BUFF_SIZE 1024
#endif
