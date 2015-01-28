/*
** main.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc/src
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 13:15:19 2015 kruszk_t
** Last update Wed Jan 28 11:34:30 2015 kruszk_t
*/

#include	<unistd.h>
#include	"malloc.h"

/* void		my_putchar(char c) */
/* { */
/*   write(1, &c, 1); */
/* } */

/* void		my_putstr(char *str) */
/* { */
/*   int		i; */

/*   for (i = 0; str[i]; i++) */
/*     my_putchar(str[i]); */
/* } */

/* int		my_strlen(char *str) */
/* { */
/*   int		i; */

/*   for (i = 0; str[i]; i++) */
/*     ; */
/*   return (i); */
/* } */

/* char		*my_strdup(char *str) */
/* { */
/*   char		*dest; */
/*   int		i; */

/*   if (!(dest = malloc(sizeof(char) * my_strlen(str) + 1))) */
/*     return (NULL); */
/*   for (i = 0; str[i]; i++) */
/*     dest[i] = str[i]; */
/*   dest[i] = 0; */
/*   return (dest); */
/* } */

int		main()
{
  char		*str = malloc(10);
  str = str + 5;
  free(str);
  return (0);
}
