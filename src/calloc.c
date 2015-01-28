/*
** calloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 11:23:47 2015 kruszk_t
** Last update Wed Jan 28 11:28:39 2015 kruszk_t
*/

#include	<stdlib.h>
#include	"malloc.h"

void		*calloc(size_t n, size_t t)
{
  char		*ret;
  size_t	i;

  if (!n || !t)
    return (NULL);
  if (!(ret = malloc(n * t)))
    return (NULL);
  for (i = 0; i < n * t; ++i)
    ret[i] = 0;
  return ((void*)ret);
}
