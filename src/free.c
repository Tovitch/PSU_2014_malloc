/*
** free.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Wed Jan 28 10:11:18 2015 kruszk_t
** Last update Wed Jan 28 10:21:35 2015 kruszk_t
*/

#include	"malloc.h"

extern size_t	alloc_nb;

void		free(void *ptr)
{
  t_metaData	*m;

  if (!ptr)
    return ;
  m = (t_metaData*)ptr - 1;
  m->free = 1;
  --alloc_nb;
}
