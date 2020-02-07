/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:49:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcat(void *d, const void *s, size_t dl, size_t sl)
{
	unsigned char	*cur;
	unsigned char	*cur2;

	cur = (unsigned char *)d + dl;
	cur2 = (unsigned char *)s;
	while (sl--)
		*cur++ = *cur2++;
	return (d);
}
