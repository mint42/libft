/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:57:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:09:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memsec(malloc(size + 1), 0, size + 1));
}
