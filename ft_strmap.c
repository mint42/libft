/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:28:35 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/02 17:34:24 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	char	*cur;

	if (!s || !f)
		return (0);
	str = ft_strnew(ft_strlen(s));
	cur = str;
	while (cur && *s)
		*cur++ = f(*s++);
	return (str);
}
