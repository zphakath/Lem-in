# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zphakath <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 15:56:29 by zphakath          #+#    #+#              #
#    Updated: 2018/07/05 17:03:55 by zphakath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin

SRC = ants_move.c free_ptr.c main.c rooms.c get_next_line.c queue.c \
	  utils.c

FLAG = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
	@make -C libft 
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(OBJ)  libft/libft.a -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft $(SILENT)

re: fclean all
