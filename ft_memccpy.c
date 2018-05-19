/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:01:49 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/15 13:21:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cur;
	unsigned char	*cur2;

	cur = (unsigned char *)dst;
	cur2 = (unsigned char *)src;
	while (n--)
	{
		*cur++ = *cur2++;
		if ((*cur - 1) == (unsigned char)c)
			return (cur++);
	}
	*cur = '\0';
	return (cur);
}
