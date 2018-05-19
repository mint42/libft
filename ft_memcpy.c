/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:30:37 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/17 20:28:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cur;
	unsigned char	*cur2;

	cur = (unsigned char *)dst;
	cur2 = (unsigned char *)src;
	while (n--)
		*cur++ = *cur2++;
	return (dst);
}
