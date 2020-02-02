# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 00:16:25 by rreedy            #+#    #+#              #
#    Updated: 2020/02/02 00:43:05 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
INCLUDES := -I./includes -I./includes/ft_printf
CFLAGS := -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += $(INCLUDES)
LFLAGS += -L./ -lft

MODS := ft_binarytree\
		ft_conv\
		ft_double_array\
		ft_list\
		ft_math\
		ft_mem\
		ft_parse\
		ft_printf\
		ft_put\
		ft_queue\
		ft_stack\
		ft_str\
		ft_utils\
		get_next_line

NAME_COLOR := \e[1;33m
COMPILE_COLOR := \e[1;32m
DOTS_COLOR := \e[0;36m
FINISH_COLOR := \e[0;32m
CLEAR_COLOR := \e[m
DELETE_COLOR := \e[0;31m
