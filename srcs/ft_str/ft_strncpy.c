/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:04:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>

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
