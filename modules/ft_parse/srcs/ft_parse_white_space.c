/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_white_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:09:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 10:25:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

char	*ft_parse_white_space(char **s, size_t *len)
{
	char	*space;

	if (!(*s))
		return (0);
	space = *s;
	*len = 0;
	while (ft_isspace((*s)[*len]))
		++(*len);
	*s = *s + *len;
	return (space);
}
