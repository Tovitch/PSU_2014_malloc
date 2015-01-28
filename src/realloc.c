/*
** realloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:13:18 2015 kruszk_t
** Last update Wed Jan 28 12:05:28 2015 kruszk_t
*/

#include	<stdlib.h>
#include	<string.h>
#include	"malloc.h"

void		*realloc(void *ptr, size_t size)
{
  void		*ret;

  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  if (!(ret = malloc(size)))
    return (NULL);
  if (!ptr)
    return (ret);
  memcpy(ret, ptr, size);
  free(ptr);
  return (ret);
}
