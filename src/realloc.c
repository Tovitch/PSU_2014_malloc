/*
** realloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:13:18 2015 kruszk_t
** Last update Thu Jun 18 18:41:27 2015 Tony Kruszkewycz
*/

#include		<stdlib.h>
#include		<string.h>
#include		"malloc.h"

extern t_metaData	*g_head;
extern t_metaData	*g_tail;

void			*realloc(void *ptr, size_t size)
{
  void			*ret;

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
