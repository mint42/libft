/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 09:27:54 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/14 20:51:32 by rreedy           ###   ########.fr       */
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
		while ((*haystack++ == *needle++) && *needle)
			i++;
		if (i == ft_strlen(needle))
			return ((char *)haystack - ft_strlen(needle));
		needle = needle - i;
		i = 0;
	}
	return (0);
}
