##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles mylib
##

CC 		=	gcc

SRC 	=	main.c	\
		open_read.c	\
		bsq.c	\
		full_array.c	\
		find_square_in_filled_or_empty.c	\
		print_array.c	\
		find_square_in_int_map.c	\
		put_zero_and_one.c    \
		display_map_solve.c	\
		gestion_error.c	\
		create_map.c	\

LIB		=	lib/my_strlen.c	\
			lib/getnbr.c	\
			lib/my_put_nbr.c	\
			lib/my_putchar.c	\
			lib/my_getnbr.c	\

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	bsq

INCLUDES	=	-I includes/

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all: 	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find . \( -name "*~" -o -name "#*" -o -name "*#" -o -name "vg*" \) -delete

fclean: clean
	rm -f $(NAME)

re: 	fclean all
