/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:58:04 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 10:24:10 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

ssize_t		ft_parse_number(char **s, size_t *len)
{
	ssize_t		n;
	uint8_t		sign;

	if (!(*s))
		return (0);
	n = 0;
	sign = 1;
	*len = 0;
	if ((*s)[*len] == '+')
		++(*len);
	else if ((*s)[*len] == '-')
	{
		sign = -1;
		++(*len);
	}
	while (ft_isdigit((*s)[*len]))
	{
		n = n * 10 + ((*s)[*len] - 48);
		++(*len);
	}
	*s = *s + *len;
	return (sign * n);
}
