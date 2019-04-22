# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    modules.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:24:06 by rreedy            #+#    #+#              #
#    Updated: 2019/04/22 00:24:11 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

DIR := ./srcs/$(NAME)
OBJS := $(patsubst %.c,%.o,$(wildcard $(DIR)/*.c))

.PHONY: $(NAME) start stop clean

$(NAME): start $(OBJS) stop


start:
	@ printf "$(COMPILE_COLOR)Compiling $(NAME_COLOR)$(NAME) $(DOTS_COLOR)"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "."
	
stop:
	@ printf "$(FINISH_COLOR) done$(CLEAR_COLOR)\n"

clean:
	@ if $(foreach OBJ, $(OBJS),[ -f $(OBJ) ] ||) false; then \
		printf "$(DELETE_COLOR)Cleaning $(NAME_COLOR)$(NAME)$(CLEAR_COLOR)\n"; \
	  fi; 
	@- $(RM) $(OBJS)
