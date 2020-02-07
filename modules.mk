# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    modules.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:24:06 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:37:11 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

MOD_OBJS := $(patsubst %.c,%.o,$(MOD_SRCS))

.PHONY: $(MOD_NAME) all start stop clean

all: $(MOD_NAME)

$(MOD_NAME): start $(MOD_OBJS) stop

start:
	@ printf "$(COMPILE_COLOR)Compiling $(NAME_COLOR)$(MOD_NAME) $(DOTS_COLOR)"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ printf "."

stop:
	@ printf "$(FINISH_COLOR) done$(CLEAR_COLOR)\n"

clean:
	@ if $(foreach obj, $(MOD_OBJS),[ -f $(obj) ] ||) false; then \
		printf "$(DELETE_COLOR)Cleaning $(NAME_COLOR)$(MOD_NAME)$(CLEAR_COLOR)\n"; \
	  fi; 
	@- $(RM) $(MOD_OBJS)
