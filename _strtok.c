#include "main.h"
/**
 * _strtok - implementation of strtok
 * @string: string to be tokenized
 * @delim: delimeter
 * Return: pointer to the next token, or NULL
*/
char *_strtok(char *string, const char *delim)
{
	return (strtok(string, delim));
}
