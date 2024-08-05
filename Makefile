# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 10:55:46 by hmateque          #+#    #+#              #
#    Updated: 2024/08/05 11:43:30 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME1 = server 
NAME2 = client

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_FILE = ./ft_printf
FT_PRINTF_A = ft_printf/libftprintf.a

SRC_NAME1 = server.c
SRC_NAME2 = client.c

OBJ_NAME1 = $(SRC_NAME1:.c=.o)
OBJ_NAME2 = $(SRC_NAME2:.c=.o)

all: $(NAME)

$(NAME): $(NAME1) $(NAME2)

$(NAME1): $(OBJ_NAME1) $(FT_PRINTF_A)
	$(CC) $(FLAGS) $(OBJ_NAME1) $(FT_PRINTF_A) -o $(NAME1)

$(NAME2): $(OBJ_NAME2) $(FT_PRINTF_A)
	$(CC) $(FLAGS) $(OBJ_NAME2) $(FT_PRINTF_A) -o $(NAME2)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_FILE)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_NAME1)
	$(RM) $(OBJ_NAME2)
	$(MAKE) clean -C $(FT_PRINTF_FILE)
fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)
	$(MAKE) fclean -C $(FT_PRINTF_FILE)
re: fclean all
.PHONY: all re fclean clean