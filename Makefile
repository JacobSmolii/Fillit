# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 12:11:53 by eagulov           #+#    #+#              #
#    Updated: 2019/02/09 18:53:31 by eagulov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c checker.c add_lists.c fill_it.c load_tetrimino.c

OBJ = $(SRC:.c=.o)

INC = -I includes

LIBFT =	libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		gcc -Wall -Wextra -Werror -g $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		gcc -Wall -Wextra -Werror -g $(FLAGS) -c $(SRC)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
