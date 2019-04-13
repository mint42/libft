/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:09:40 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:08:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	return (ft_memsec(malloc(size), 0, size));
}
