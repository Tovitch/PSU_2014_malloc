/*
** free.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:11:18 2015 kruszk_t
** Last update Tue Feb 10 12:50:47 2015 kruszk_t
*/

#include	<stdio.h>
#include	"malloc.h"

extern size_t	alloc_nb;
extern t_metaData *head;
extern t_metaData *tail;

void		free(void *ptr)
{
  t_metaData	*m;
  t_metaData	*tmp;

  if (!ptr)
    return ;
  m = (t_metaData*)ptr - 1;
  if (m == tail)
    {
      tmp = head;
      while (tmp->next != m)
  	tmp = tmp->next;
      brk(m);
      tmp->next = NULL;
    }
  else
    m->free = 1;
  --alloc_nb;
}
