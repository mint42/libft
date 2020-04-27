/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:30:37 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 07:30:37 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, void *src, size_t size)
{
	unsigned long int	*fast_cur;
	unsigned char		*slow_cur;
	unsigned char		sizeoflong;

	sizeoflong = sizeof(unsigned long int);
	fast_cur = (unsigned long int *)dst;
	while (size >= sizeoflong)
	{
		*fast_cur = *(unsigned long int *)src;
		++fast_cur;
		src = src + sizeoflong;
		size = size - sizeoflong;
	}
	slow_cur = (unsigned char *)fast_cur;
	while (size > 0)
	{
		*slow_cur = *(unsigned char *)src;
		++slow_cur;
		++src;
		--size;
	}
	return (dst);
}
