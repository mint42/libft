/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:42:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:10:38 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char	*ft_strpad(char **s, int start, size_t len, char c)
{
	char	*str;
	char	*cur;

	str = ft_strinit(c, len);
	cur = *s;
	if (!str)
		return (0);
	while (cur && *cur && len)
	{
		str[start] = *cur;
		++cur;
		++start;
		--len;
	}
	ft_strdel(s);
	return (str);
}
