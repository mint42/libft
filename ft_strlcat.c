/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:34:22 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/17 16:38:48 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*cur;

	cur = dst;
	cur = cur + ft_strlen(dst);
	while (dstsize)
		*cur++ = *src++;
	if (dstsize > 0)
		*cur = '\0';
	return (ft_strlen(dst));
}
