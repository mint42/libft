/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:27:54 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 14:35:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	if (!s2)
		return ((char *)s1);
	while (*s1 && len--)
	{
		if (!ft_memcmp(s1, s2, ft_strlen(s2)))
			return ((char *)s1);
		s1++;
	}
	return (0);
}
