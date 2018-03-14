/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** memset function
*/

/* File created the 14/03/2018 at 14:28:19 by julian.frabel@epitech.eu */

#include <stdlib.h>

void *my_memset(void *s, int c, size_t n)
{
	if (s == NULL)
		return (NULL);
	for (size_t i = 0; i < n; i++)
		((unsigned char*)s)[i] = c;
	return (s);
}