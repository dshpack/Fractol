# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshpack <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 17:25:56 by dshpack           #+#    #+#              #
#    Updated: 2018/11/21 17:26:30 by dshpack          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS := -Wall -Werror -Wextra -O3

SRC := fractol.c validator.c initialization.c fractal_selector.c drawing.c\
	fractal_selector2.c event_handler.c color_handler.c error_handler.c\
	interface.c interface2.c cleaning_before_exit.c

OBJ := $(SRC:.c=.o)

LIB := ./libft/libft.a

MLX := -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	#@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) $(LIB) $(MLX) -o $(NAME) $(OBJ)
	@echo "\033[92mDONE\033[0m"

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@echo "\033[92mObject files have been deleted\033[0m"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "\033[92mExecutables have been deleted\033[0m"

re: fclean all

.PHONY:all clean fclean re
