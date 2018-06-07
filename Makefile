# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2018/06/06 20:27:05 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
