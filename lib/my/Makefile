##
## EPITECH PROJECT, 2023
## B-CPE-100-PAR-1-1-cpoolday10-anastasiia.beginia
## File description:
## Makefile
##

SRC	=	my_putstr.c \
		my_strlen.c \
		my_put_nbr.c \
		my_error_handling.c \
		my_putchar.c \
		my_strcpy.c \
		mini_printf.c \
		my_strcat.c \
		my_strdup.c \
		my_strcmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEADER_FILE	=	my.h

INCLUDE_PATH	=	../../include

all:	$(NAME)

$(NAME):
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		rm -f $(OBJ)
		cp $(HEADER_FILE) $(INCLUDE_PATH)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
