# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:16:25 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:36:47 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
LIB := ft
LIB_DIR := ./

MODS := ft_binarytree
MODS += ft_conv
MODS += ft_double_array
MODS += ft_list
MODS += ft_math
MODS += ft_mem
MODS += ft_parse
MODS += ft_printf
MODS += ft_put
MODS += ft_queue
MODS += ft_stack
MODS += ft_str
MODS += ft_utils
MODS += get_next_line

CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(foreach mod,$(MODS),-Imodules/$(mod)/includes)

NAME_COLOR := \e[1;33m
COMPILE_COLOR := \e[1;32m
DOTS_COLOR := \e[0;36m
FINISH_COLOR := \e[0;32m
CLEAR_COLOR := \e[m
DELETE_COLOR := \e[0;31m

#
#	testing
#
#	TEST_NAME := test
#	SRC_DIRS := ./test/srcs
#	INCLUDE_DIRS := ./test/includes
#	CFLAGS += $(foreach include,$(INCLUDE_DIRS),-I$(include))
#	LDFLAGS := -L$(LIB_DIR)
#	LDFLAGS := -l$(LIB)
#
