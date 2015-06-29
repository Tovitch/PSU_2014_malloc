/*
** malloc.h for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 18:17:43 2015 kruszk_t
** Last update Mon Jun 29 16:03:30 2015 Tony Kruszkewycz
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include		<unistd.h>

typedef struct		s_metaData
{
  size_t		size;
  int			free;
  struct s_metaData	*next;
}			t_metaData;

void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
int			is_ptr_list(t_metaData *ptr);
void			show_alloc_mem();

#endif /* !MALLOC_H_ */
