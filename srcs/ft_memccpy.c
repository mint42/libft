/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:01:49 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/31 16:26:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char	*cur;

	cur = (unsigned char *)dst;
	while (len--)
	{
		*cur++ = *(unsigned char *)src++;
		if (*(cur - 1) == (unsigned char)c)
			return (cur);
	}
	return (0);
}
