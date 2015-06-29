/*
** free.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:11:18 2015 kruszk_t
** Last update Mon Jun 29 12:08:06 2015 Tony Kruszkewycz
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<pthread.h>
#include		"malloc.h"

extern t_metaData	*g_head;
extern t_metaData	*g_tail;
extern pthread_mutex_t	m;

void			free(void *ptr)
{
  t_metaData		*b;
  t_metaData		*tmp;

  if (!ptr)
    return ;
  b = (t_metaData *)ptr - 1;
  pthread_mutex_lock(&m);
  if (is_ptr_list(b) == EXIT_SUCCESS)
    {
      if (b == g_tail && g_tail == g_head)
	{
	  g_head = NULL;
	  g_tail = NULL;
	  brk(b);
	}
      else if (b == g_tail)
	{
	  tmp = g_head;
	  while (tmp->next != b)
	    tmp = tmp->next;
	  tmp->next = NULL;
	  g_tail = tmp;
	  brk(b);
	}
      else
	b->free = 1;
    }
  pthread_mutex_unlock(&m);
}
