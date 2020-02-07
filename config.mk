# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:16:25 by rreedy            #+#    #+#              #
#    Updated: 2020/02/06 18:28:26 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
TEST := test

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

SRC_DIRS := $(foreach mod,$(MODS),./srcs/$(mod))
INCLUDE_DIRS := ./includes 
INCLUDE_DIRS += ./includes/ft_printf

LIBS := ft
LIB_DIRS := ./

CC := gcc
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(foreach include,$(INCLUDE_DIRS),-I$(include))
LDFLAGS := $(foreach local_lib_dirs,$(LIB_DIRS),-L$(local_lib_dirs))
LDFLAGS += $(foreach lib,$(LIBS),-l$(lib))

NAME_COLOR := \e[1;33m
COMPILE_COLOR := \e[1;32m
DOTS_COLOR := \e[0;36m
FINISH_COLOR := \e[0;32m
CLEAR_COLOR := \e[m
DELETE_COLOR := \e[0;31m
