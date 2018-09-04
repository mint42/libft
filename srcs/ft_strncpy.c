/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:04:14 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/02 16:29:20 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cur;

	cur = dst;
	while (len && *src && len--)
		*cur++ = *src++;
	if (len)
		ft_memset(cur, '\0', len);
	return (dst);
}
