/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:25:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	str = ft_strnew(len);
	if (str)
		ft_strncpy(str, s + start, len);
	return (str);
}
