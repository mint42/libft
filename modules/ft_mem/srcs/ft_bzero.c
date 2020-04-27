/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:54:55 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 07:32:07 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>

void	ft_bzero(void *ptr, size_t size)
{
	unsigned long int	*fast_cur;
	unsigned long int	zero;
	unsigned char		*slow_cur;
	unsigned char		sizeoflong;

	sizeoflong = sizeof(unsigned long int);
	fast_cur = (unsigned long int *)ptr;
	zero = 0;
	while (size >= sizeoflong)
	{
		*fast_cur = zero;
		++fast_cur;
		ptr = ptr + sizeoflong;
		size = size - sizeoflong;
	}
	slow_cur = (unsigned char *)fast_cur;
	while (size > 0)
	{
		*slow_cur = (unsigned char)zero;
		++slow_cur;
		++ptr;
		--size;
	}
}
