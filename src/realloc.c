/*
** realloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:13:18 2015 kruszk_t
** Last update Fri Jun 26 10:47:43 2015 Tony Kruszkewycz
*/

#include		<stdlib.h>
#include		<string.h>
#include		"malloc.h"

extern t_metaData	*g_head;
extern t_metaData	*g_tail;

void			*realloc(void *ptr, size_t size)
{
  t_metaData		*tmp;
  t_metaData		*b;
  void			*ret;

  b = (t_metaData *)ptr - 1;
  tmp = g_head;
  while (tmp && tmp != b)
    tmp = tmp->next;
  if (tmp == b)
    {
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
  return (NULL);
}
