##
## Makefile for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
## 
## Made by kruszk_t
## Login   <kruszk_t@epitech.net>
## 
## Started on  Sun Feb 15 16:48:10 2015 kruszk_t
## Last update Sun Feb 15 17:08:17 2015 kruszk_t
##


SRC		= src/malloc.c		\
		  src/realloc.c		\
		  src/calloc.c		\
		  src/free.c		\
		  src/show_alloc_mem.c

NAME		= libmy_malloc_$(HOSTTYPE).so

OBJ		= $(SRC:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wall -Wextra -ansi -pedantic -I./inc -D_BSD_SOURCE

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -fPIC -shared $(SRC) -o $(NAME) -I./inc

clean:
		$(RM) $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
