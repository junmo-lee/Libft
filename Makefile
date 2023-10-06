# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:31:11 by junmlee           #+#    #+#              #
#    Updated: 2023/10/06 19:21:59 by junmlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc -Wall -Wextra -Werror

RM		= rm
RMFLAG	= -rf

AR		= ar
ARFLAGS	= -rcus

INCLUDES	= ./includes/ft.h

SRCS		= ./srcs/ft_putchar.c \
	        ./srcs/ft_swap.c \
            ./srcs/ft_putstr.c	\
            ./srcs/ft_strlen.c \
			./srcs/ft_strcmp.c

OBJS		= $(SRCS:.c=.o)

.PHONY : all clean fclean re

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) -c $< -o $@ -I$(INCLUDES)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean :
	$(RM) $(RMFLAG) $(OBJS) $(NAME)

re : fclean all
