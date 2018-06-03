/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:34:22 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/02 19:12:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;

	dlen = ft_strlen(dst);
	dst = dst + ft_strlen(dst);
	dstsize = dstsize - ft_strlen(dst) - 1;
	while (dstsize-- > 0 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dlen + ft_strlen(src));
}
