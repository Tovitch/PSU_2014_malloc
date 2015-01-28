##
## Makefile for malloc in /home/kruszk_t/rendu/PSU_2014_malloc
## 
## Made by kruszk_t
## Login   <kruszk_t@epitech.net>
## 
## Started on  Tue Jan 27 12:20:04 2015 kruszk_t
## Last update Wed Jan 28 12:07:11 2015 kruszk_t
##

SRC		= src/main.c

SRC_LIB		= src/malloc.c		\
		  src/realloc.c		\
		  src/calloc.c		\
		  src/free.c

NAME		= malloc

OBJ		= $(SRC:.c=.o)

OBJ_LIB		= $(SRC_LIB:.c=.o)

CC		= gcc

LIBNAME		= libmy_malloc_$(HOSTTYPE).so

RM		= rm -f

CFLAGS		+= -Wall -Wextra -ansi -pedantic -D_BSD_SOURCE

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -fPIC -shared $(SRC_LIB) -o $(LIBNAME) -I./inc
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ) $(OBJ_LIB)

fclean:		clean
		rm -f $(NAME) $(LIBNAME)

re:		fclean all

.PHONY:		all clean fclean re
