/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:27:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"
#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if (!(*s2))
		return ((char *)s1);
	while (*s1 && (int)(len - ft_strlen(s2) + 1) > 0)
	{
		if (!ft_memcmp(s1, s2, ft_strlen(s2)))
			return ((char *)s1);
		++s1;
		--len;
	}
	return (0);
}
