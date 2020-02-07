/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:28:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

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
