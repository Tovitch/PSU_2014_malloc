/*
** main.c for malloc in /home/kruszk_t/rendu/PSU_2014_malloc/src
**
** Made by kruszk_t
** Login   <kruszk_t@epitech.net>
**
** Started on  Tue Jan 27 13:15:19 2015 kruszk_t
** Last update Tue Feb 10 11:41:16 2015 kruszk_t
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

#include	"malloc.h"

void		show_alloc_mem();

int		main()
{
  char		*str;
  char		*str2;
  char		*str3;
  char		*str4;

  str = malloc(6);
  str2 = malloc(12);
  str3 = malloc(18);
  str4 = malloc(24);
  show_alloc_mem();
  free(str);
  free(str2);
  free(str3);
  free(str4);
  show_alloc_mem();
  str = malloc(6);
  return (0);
}
