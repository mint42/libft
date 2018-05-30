/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:41:36 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 14:32:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (!needle)
		return ((char *)haystack);
	while (*haystack++)
	{
		while ((*haystack++ == needle[i]) && needle[i])
			i++;
		if (i == ft_strlen(needle))
			return ((char *)haystack - i);
		i = 0;
	}
	return (0);
}
