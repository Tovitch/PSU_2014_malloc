/*
** realloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:13:18 2015 kruszk_t
** Last update Mon Jun 29 10:55:46 2015 Tony Kruszkewycz
*/

#include		<stdlib.h>
#include		<string.h>
#include		"malloc.h"

extern t_metaData	*g_head;
extern t_metaData	*g_tail;

int			is_ptr_list(t_metaData *ptr)
{
  t_metaData		*tmp;

  tmp = g_head;
  while (tmp)
    {
      if (tmp == ptr)
	return (EXIT_SUCCESS);
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}

void			*realloc(void *ptr, size_t size)
{
  t_metaData		*b;
  void			*ret;

  b = (t_metaData *)ptr - 1;
  if (is_ptr_list(b) == EXIT_SUCCESS)
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
  return (malloc(size));
}
