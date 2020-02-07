# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_get_next_line                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 01:42:08 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:41:27 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOD_NAME := get_next_line
MOD_SRCS := $(wildcard modules/$(MOD_NAME)/srcs/*.c)

include config.mk
include modules.mk
