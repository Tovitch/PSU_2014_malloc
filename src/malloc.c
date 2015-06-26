/*
** malloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 12:27:26 2015 kruszk_t
** Last update Fri Jun 26 10:49:51 2015 Tony Kruszkewycz
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"malloc.h"

t_metaData	*g_head = NULL;
t_metaData	*g_tail = NULL;

t_metaData	*find_block(t_metaData **curr, size_t size)
{
  if (*curr)
    {
      if ((*curr)->free == 1 && (*curr)->size == size)
  	{
  	  (*curr)->free = 0;
  	  return (*curr + 1);
  	}
      else
  	{
  	  while ((*curr)->next)
  	    {
  	      if ((*curr)->next->free == 1 && (*curr)->next->size == size)
  		{
  		  (*curr)->next->free = 0;
  		  return ((*curr)->next + 1);
  		}
  	      *curr = (*curr)->next;
  	    }
  	}
    }
  return (NULL);
}

void		*malloc(size_t taille)
{
  t_metaData	*curr;
  t_metaData	*tmp;
  void		*start;
  t_metaData	*new;

  if (!taille)
    return (NULL);
  taille = ALIGN8(taille);
  curr = g_head;
  if ((tmp = find_block(&curr, taille)) != NULL)
    return (tmp);
  if ((start = sbrk(sizeof(t_metaData) + taille)) == (void *)-1)
    return (NULL);
  new = start;
  new->size = taille;
  new->free = 0;
  new->next = NULL;
  g_tail = new;
  if (!g_head)
    g_head = new;
  else
    curr->next = new;
  return (new + 1);
}

void		show_alloc_mem()
{
  t_metaData	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = g_head;
  while (tmp)
    {
      if (tmp->free == 0)
	printf("%p - %p : %u octets\n", (void *)(tmp + sizeof(t_metaData)),
	       (void *)(tmp + tmp->size + sizeof(t_metaData)),
	       (unsigned int)tmp->size);
      tmp = tmp->next;
    }
}
