# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    modules.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:24:06 by rreedy            #+#    #+#              #
#    Updated: 2020/04/29 08:39:31 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk

MOD_PATH := ./modules/$(MOD_NAME)
MOD_SRCS := $(wildcard $(MOD_PATH)/srcs/*.c)
MOD_OBJS := $(patsubst %.c,%.o,$(MOD_SRCS))

.PHONY: all start stop clean

$(MOD_NAME): start $(MOD_OBJS) stop
	@- ln -s .$(MOD_PATH)/includes/$(MOD_NAME).h $(SYM_INCLUDES_DIR)

start:
	@ printf "$(COMPILE_COLOR)Compiling $(NAME_COLOR)$(MOD_NAME) $(DOTS_COLOR)"

%.o: %.c
	@ $(CC) $(CFLAGS) -I$(MOD_PATH)/includes -c $< -o $@
	@ printf "."

stop:
	@ printf "$(FINISH_COLOR) done$(CLEAR_COLOR)\n"

clean:
	@ if $(foreach obj, $(MOD_OBJS),[ -f $(obj) ] ||) false; then \
		printf "$(DELETE_COLOR)Cleaning $(NAME_COLOR)$(MOD_NAME)$(CLEAR_COLOR)\n"; \
	  fi; 
	@- $(RM) $(MOD_OBJS)
