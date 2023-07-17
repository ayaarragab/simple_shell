#include "main.h"
/**
 * _getline - implementation of getline
 * @command_buff: buffer stores command
 * @n: size
 * @_stdin: the file
 * Return: num of characters and -1 in error
*/
ssize_t _getline(char **command_buff, size_t *n, FILE *_stdin)
{
    return (getline(command_buff, n, _stdin));
}
