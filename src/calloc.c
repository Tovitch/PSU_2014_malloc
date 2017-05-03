/*
** calloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 11:23:47 2015 kruszk_t
** Last update Fri Jun 19 14:08:45 2015 Tony Kruszkewycz
*/

#include	<stdlib.h>
#include	<string.h>
#include	"malloc.h"

void		*calloc(size_t n, size_t t)
{
  void		*ret;
  size_t	size;

  if (!n || !t)
    return (NULL);
  size = n * t;
  if (!(ret = malloc(size)))
    return (NULL);
  bzero(ret, size);
  return (ret);
}
