# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    modules.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:24:06 by rreedy            #+#    #+#              #
#    Updated: 2020/02/06 18:40:51 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

DIR := ./srcs/$(MOD_NAME)
OBJS := $(patsubst %.c,%.o,$(wildcard $(DIR)/*.c))

.PHONY: $(MOD_NAME) all start stop clean

all: $(MOD_NAME)

$(MOD_NAME): start $(OBJS) stop

start:
	@ printf "$(COMPILE_COLOR)Compiling $(NAME_COLOR)$(MOD_NAME) $(DOTS_COLOR)"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "."

stop:
	@ printf "$(FINISH_COLOR) done$(CLEAR_COLOR)\n"

clean:
	@ if $(foreach obj, $(OBJS),[ -f $(obj) ] ||) false; then \
		printf "$(DELETE_COLOR)Cleaning $(NAME_COLOR)$(MOD_NAME)$(CLEAR_COLOR)\n"; \
	  fi; 
	@- $(RM) $(OBJS)
