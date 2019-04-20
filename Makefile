# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2019/04/20 12:48:46 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
TEST := main

INCLUDES := -I./includes -I./includes/ft_printf
CFLAGS += -Wall -Wextra -Werror $(INCLUDES)
LFLAGS += -L./ -lft
MODS := ft_binarytree\
		ft_conv\
		ft_double_array\
		ft_list\
		ft_math\
		ft_mem\
		ft_printf\
		ft_put\
		ft_queue\
		ft_stack\
		ft_str\
		ft_utils\
		get_next_line

# colors #
NAME_COLOR := \e[1;33m
COMPILE_COLOR := \e[1;32m
DOTS_COLOR := \e[0;36m
FINISH_COLOR := \e[0;32m
CLEAR_COLOR := \e[m
DELETE_COLOR := \e[0;31m

.PHONY: $(MODS) modules test all clean fclean re

all: $(NAME)

$(NAME): modules
	@ printf "$(COMPILE_COLOR)Creating  $(NAME_COLOR)$(NAME) "
	@ ar rc $(NAME) $(shell find srcs -name "*.o")
	@ printf "$(DOTS_COLOR)."
	@ ranlib $(NAME)
	@ printf "."
	@ printf " $(FINISH_COLOR) done$(CLEAR_COLOR)\n"

modules:
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./makefiles/$(MOD);)

test: all $(TEST).o
	$(CC) $(CFLAGS) $(TEST).o $(INCLUDES) $(LFLAGS)

clean:
	@- $(RM) $(TEST).o
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./makefiles/$(MOD) clean;)

fclean: clean
	@- $(RM) a.out
	@- if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			printf "$(DELETE_COLOR)Removing $(NAME_COLOR)$(NAME)\n"; \
	   fi;

re: fclean all
