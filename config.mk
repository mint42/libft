# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:16:25 by rreedy            #+#    #+#              #
#    Updated: 2020/04/26 23:05:14 by mint             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft_mods.mk

ALL_MODS := ft_binarytree
ALL_MODS += ft_conv
ALL_MODS += ft_double_array
ALL_MODS += ft_list
ALL_MODS += ft_math
ALL_MODS += ft_mem
ALL_MODS += ft_parse
ALL_MODS += ft_printf
ALL_MODS += ft_put
ALL_MODS += ft_queue
ALL_MODS += ft_stack
ALL_MODS += ft_str
ALL_MODS += ft_utils
ALL_MODS += get_next_line

MOD_DEPS := $(wildcard ./modules/*/deps.mk)

ifeq ($(strip $(MODS)),)
	MODS=$(ALL_MODS)
endif

NAME := libft.a
LIB := ft
LIB_DIR := ./
SYM_INCLUDES_DIR := ./includes

CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -I$(SYM_INCLUDES_DIR)

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
#	LDFLAGS += -l$(LIB)
#
