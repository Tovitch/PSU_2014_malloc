/*
** free.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:11:18 2015 kruszk_t
** Last update Fri Jun 19 13:53:29 2015 Tony Kruszkewycz
*/

#include	<stdio.h>
#include	"malloc.h"

extern t_metaData *g_head;
extern t_metaData *g_tail;

void		free(void *ptr)
{
  t_metaData	*m;
  t_metaData	*tmp;

  if (!ptr)
    return ;
  m = (t_metaData*)ptr - 1;
  if (m == g_tail && g_head != g_tail)
    {
      tmp = g_head;
      while (tmp->next != m)
      	tmp = tmp->next;
      tmp->next = NULL;
      brk(m);
    }
  else
    m->free = 1;
}
