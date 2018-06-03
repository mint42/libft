/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:17:03 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/31 16:27:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*cur;

	cur = (unsigned char *)s;
	while (len--)
		if (*cur++ == (unsigned char)c)
			return (--cur);
	return (0);
}
