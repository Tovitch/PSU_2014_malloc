/*
** malloc.h for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 18:17:43 2015 kruszk_t
** Last update Wed Jan 28 10:18:35 2015 kruszk_t
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

#endif /* !MALLOC_H_ */
