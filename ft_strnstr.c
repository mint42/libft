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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle)
		return ((char *)haystack);
	while (*haystack++ && len--)
	{
		while ((*haystack++ == needle[i]) && needle[i])
			i++;
		if (i == ft_strlen(needle))
			return ((char *)haystack - i);
		i = 0;
	}
	return (0);
}
