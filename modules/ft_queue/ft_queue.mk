# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_queue                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 12:49:13 by rreedy            #+#    #+#              #
#    Updated: 2020/02/07 00:41:27 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MOD_NAME := ft_queue
MOD_SRCS := $(wildcard modules/$(MOD_NAME)/srcs/*.c)

include modules.mk