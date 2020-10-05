# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alpha <alpha@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/27 02:59:48 by alpha         #+#    #+#                  #
#    Updated: 2020/10/05 14:10:34 by okruitho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test

NASM = nasm -f macho64

SRC = src/ft_strcmp.s	\
	src/ft_strcpy.s	\
	src/ft_strlen.s	\
	src/ft_read.s	\
	src/ft_write.s	\
	src/ft_strdup.s	\

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME):
	for i in $(SRC); do \
		$(NASM) $$i; \
	done
	ar rcs $(NAME) $(OBJ)

test: re all
	gcc -o libasm-test test.c -L. -lasm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all