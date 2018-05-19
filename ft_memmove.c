/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:03:28 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/15 13:35:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cur;
	char	*cur2;
	char	*temp;
	size_t	i;

	cur = (char *)dst;
	cur2 = (char *)src;
	temp = (char *)malloc(sizeof(char *) * len);
	i = len;
	cur = (char *)dst;
	while (len--)
		*temp++ = *cur2++;
	temp = temp - i;
	while (i--)
		*cur++ = *temp++;
	return (dst);
}
