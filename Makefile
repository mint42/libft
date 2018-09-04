# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2018/09/03 20:38:51 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
OBJS	:= $(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
CFLAGS	+= -Wall -Wextra -Werror -I./includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	@- $(RM) $(OBJS)

fclean: clean
	@- $(RM) $(NAME)

re: fclean all
