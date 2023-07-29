# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleepago <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 15:27:51 by pleepago          #+#    #+#              #
#    Updated: 2023/07/29 12:14:21 by pleepago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = libft/

PUSHSWAP_SRCS = push_swap.c command.c stack.c handle.c instruction.c cases.c check.c extra.c main.c

#LIBFT_SRCS = ft_atoi.c ft_isdigit.c ft_split.c ft_strjoin.c ft_memcpy.c ft_strlen.c

LIBFT = libft/libft.a

SRCS = $(PUSHSWAP_SRCS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -L./libft -lft

$(LIBFT):
	make -C libft
	
clean:
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
