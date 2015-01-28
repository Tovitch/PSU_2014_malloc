/*
** malloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 12:27:26 2015 kruszk_t
** Last update Wed Jan 28 11:46:10 2015 kruszk_t
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"malloc.h"

t_metaData	*head = NULL;
t_metaData	*tail = NULL;
size_t		alloc_nb = 0;

void		*malloc(size_t taille)
{
  t_metaData	*curr;
  size_t	stop;
  void		*start;
  void		*ret;
  t_metaData	*new;

  curr = head;
  if (curr)
    {
      if (curr->free == 1 && curr->size == taille)
	{
	  curr->free = 0;
	  return (curr + 1);
	}
      else
	{
	  stop = 0;
	  while (curr->next && stop < alloc_nb)
	    {
	      if (curr->next->free == 1 && curr->next->size == taille)
		{
		  curr->free = 0;
		  return (curr->next + 1);
		}
	      ++stop;
	      curr = curr->next;
	    }
	}
    }
  start = sbrk(sizeof(t_metaData) + taille);
  ret = start + sizeof(t_metaData);
  new = start;
  new->size = taille;
  new->free = 0;
  new->next = tail;
  ++alloc_nb;
  tail = new;
  if (!head)
    head = start;
  else
    curr->next = new;
  return (ret);
}
