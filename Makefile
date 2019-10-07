# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmajstru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 15:26:41 by gmajstru          #+#    #+#              #
#    Updated: 2018/06/29 15:51:55 by gmajstru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c \
		checks.c \
		reader.c \
		resolver.c \
		tet.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft
		gcc -Wall -Werror -Wextra -c $(SRC)
		gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME) -L./libft -lft

clean:
		make -C libft clean
		rm -rf $(OBJ)

fclean: clean
		make -C libft fclean
		rm -rf $(NAME)

re : fclean all
