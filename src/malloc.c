/*
** malloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 12:27:26 2015 kruszk_t
** Last update Sun Feb 15 17:13:17 2015 kruszk_t
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"malloc.h"

#define ALIGN(x) (((((x) - 1) >> 2) << 2) + 4)

t_metaData	*head = NULL;
t_metaData	*tail = NULL;
size_t		alloc_nb = 0;

void		*malloc(size_t taille)
{
  t_metaData	*curr;
  void		*start;
  void		*ret;
  t_metaData	*new;

  if (!taille)
    return (NULL);
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
  	  while (curr->next)
  	    {
  	      if (curr->next->free == 1 && curr->next->size == taille)
  		{
  		  curr->next->free = 0;
  		  return (curr->next + 1);
  		}
  	      curr = curr->next;
  	    }
  	}
    }
  if ((start = sbrk(sizeof(t_metaData) + taille)) == (void*) -1)
    return (NULL);
  ret = start + sizeof(t_metaData);
  new = start;
  new->size = taille;
  new->free = 0;
  new->next = NULL;
  tail = new;
  ++alloc_nb;
  if (!head)
    head = new;
  else
    curr->next = new;
  return (ret);
}

void		show_alloc_mem()
{
  t_metaData	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = head;
  while (tmp)
    {
      if (tmp->free == 0)
	printf("%p - %p : %zu octets\n", tmp + sizeof(t_metaData),
	       tmp + tmp->size + sizeof(t_metaData),
	       tmp->size);
      tmp = tmp->next;
    }
}
