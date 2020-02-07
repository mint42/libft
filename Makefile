# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:31:20 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:06:51 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

.PHONY: modules all clean fclean re

all: $(NAME)

$(NAME): modules
	@ printf "$(COMPILE_COLOR)Creating  $(NAME_COLOR)$(NAME) "
	@ ar rc $(NAME) $(shell find modules -name "*.o")
	@ printf "$(DOTS_COLOR)."
	@ ranlib $(NAME)
	@ printf "."
	@ printf " $(FINISH_COLOR) done$(CLEAR_COLOR)\n"

modules:
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./modules/$(MOD)/$(MOD).mk;)

clean:
	@ $(foreach MOD, $(MODS), $(MAKE) --no-print-directory -f ./modules/$(MOD)/$(MOD).mk clean;)

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

