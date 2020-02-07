# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_binarytree                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 01:40:52 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:29:49 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOD_NAME := ft_binarytree
MOD_SRCS := $(wildcard modules/$(MOD_NAME)/srcs/*.c)

include modules.mk
