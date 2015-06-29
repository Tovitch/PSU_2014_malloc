/*
** malloc.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 12:27:26 2015 kruszk_t
** Last update Mon Jun 29 16:02:31 2015 Tony Kruszkewycz
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<pthread.h>
#include		"malloc.h"

t_metaData		*g_head = NULL;
t_metaData		*g_tail = NULL;
pthread_mutex_t		m = PTHREAD_MUTEX_INITIALIZER;

static t_metaData	*find_block(t_metaData **curr, size_t size)
{
  if (*curr)
    {
      while ((*curr)->next)
	{
	  if ((*curr)->free == 1 && (*curr)->size >= size)
	    {
	      (*curr)->free = 0;
	      return ((*curr) + 1);
	    }
	  *curr = (*curr)->next;
	}
    }
  return (NULL);
}

static t_metaData	*add_new_node(t_metaData *curr, void *start, size_t size)
{
  t_metaData		*new;

  new = start;
  new->size = size;
  new->free = 0;
  new->next = NULL;
  g_tail = new;
  if (!g_head)
    g_head = new;
  else
    curr->next = new;
  return (new);
}

void		*malloc(size_t taille)
{
  t_metaData	*curr;
  t_metaData	*tmp;
  t_metaData	*new;
  void		*start;

  if (!taille)
    return (NULL);
  pthread_mutex_lock(&m);
  curr = g_head;
  if ((tmp = find_block(&curr, taille)) != NULL)
    {
      pthread_mutex_unlock(&m);
      return (tmp);
    }
  if ((start = sbrk(sizeof(t_metaData) + taille)) == (void *)-1)
    {
      pthread_mutex_unlock(&m);
      return (NULL);
    }
  new = add_new_node(curr, start, taille);
  pthread_mutex_unlock(&m);
  return (new + 1);
}

void		show_alloc_mem()
{
  t_metaData	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = g_head;
  while (tmp)
    {
      printf("%p - %p : %u octets (free:%d)\n",
	     (void *)(tmp + sizeof(t_metaData)),
	     (void *)(tmp + tmp->size + sizeof(t_metaData)),
	     (unsigned int)tmp->size, tmp->free);
      tmp = tmp->next;
    }
}
