##
## EPITECH PROJECT, 2023
## B-CPE-101-PAR-1-1-myprintf-anastasiia.beginia
## File description:
## Makefile
##

SRC	=	file_getter.c \
		check_error.c \
		sorter.c \
		printer.c \
		parser.c \
		helper.c \
		long_printer.c \
		my_ls.c \
		rec_file_getter.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

INC	=	-I ../include

LIB	=	-L ./lib/my -lmy

all:	$(NAME)

$(NAME):	$(SRC)
		make -sC ./lib/my
		gcc $(SRC) -c $(INC)
		gcc $(OBJ) -o $(NAME) $(LIB)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
