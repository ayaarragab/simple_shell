#include "main.h"
#include <stdlib.h>
/**
 * _setenv - adds or changes environment variables
 * @name: name of variable
 * @value: value
 * @overwrite: overwrite
 * Return: integer value or -1 in failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	return (setenv(name, value, overwrite));
}
