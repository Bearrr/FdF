#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ireva <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 17:26:49 by ireva             #+#    #+#              #
#    Updated: 2017/10/31 18:32:26 by ireva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC =  validation.c main.c get_next_line.c create_map.c mlx.c turning.c norma.c zoom.c bresen.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

LIBFT_I = ./libft/libft.h

LIBFT = ./libft/

all: $(LIBFT)libft.a $(NAME)

$(NAME):  $(OBJECTS)
	@gcc $(OBJECTS) $(LIBFT)libft.a -o $(NAME) -lmlx -framework OpenGl -framework AppKit
	@echo "\033[31mCompleted!!!\033[0m"

%.o: %.c
	@gcc -c $< $(CFLAGS) -o $@

$(LIBFT)libft.a:
	@make -C $(LIBFT)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all