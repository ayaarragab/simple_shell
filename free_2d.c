#include "main.h"
/**
 * free_2d - frees a 2d array
 * @arr_2D: 2d arr
 * Return: nothing
*/
void free_2d(char **arr_2D)
{
	int i;

	for (i = 0; arr_2D[i] != NULL; i++)
		free(arr_2D[i]);
	free(arr_2D);
}
