/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stresize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:35:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char	*ft_stresize(char **s, int start, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (!str)
		return (0);
	ft_strncpy(str, *s + start, len);
	ft_strdel(s);
	return (str);
}
