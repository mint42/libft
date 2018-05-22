/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:03:28 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/21 16:33:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cur;
	char	*temp;
	size_t	i;

	temp = (char *)malloc(sizeof(char *) *len);
	cur = (char *)dst;
	i = len;
	while (len--)
		*temp++ = *(char *)src++;
	temp = temp - i;
	while (i--)
		*cur++ = *temp++;
	return (dst);
}
