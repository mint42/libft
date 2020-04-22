# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2020/04/22 15:59:10 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

.PHONY: $(MODS) all clean fclean re

all: $(NAME)

$(NAME): $(MODS)
	@ printf "$(COMPILE_COLOR)Creating  $(NAME_COLOR)$(NAME) "
	@ ar rc $(NAME) $(shell find modules -name "*.o")
	@ printf "$(DOTS_COLOR)."
	@ ranlib $(NAME)
	@ printf "."
	@ printf " $(FINISH_COLOR) done$(CLEAR_COLOR)\n"

-include $(MOD_DEPS)

$(ALL_MODS):
	@ MOD_NAME=$@ $(MAKE) --no-print-directory -f modules.mk

clean:
	@ $(foreach mod, $(ALL_MODS), MOD_NAME=$(mod) $(MAKE) --no-print-directory -f modules.mk clean;)

fclean: clean
	@- if [ -f $(NAME) ]; then \
			$(RM) $(NAME); \
			printf "$(DELETE_COLOR)Removing $(NAME_COLOR)$(NAME)\n"; \
	   fi;

re: fclean all

#
# test: all $(TEST).o
# 	$(CC) $(CFLAGS) $(TEST).o $(INCLUDES) $(LDFLAGS)
#
