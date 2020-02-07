# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2020/02/06 18:41:47 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

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
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./modules/$(MOD).mk;)

test: all $(TEST).o
	$(CC) $(CFLAGS) $(TEST).o $(INCLUDES) $(LDFLAGS)

clean:
	@- $(RM) $(TEST).o
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./modules/$(MOD).mk clean;)

fclean: clean
	@- $(RM) a.out
	@- if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			printf "$(DELETE_COLOR)Removing $(NAME_COLOR)$(NAME)\n"; \
	   fi;

re: fclean all
