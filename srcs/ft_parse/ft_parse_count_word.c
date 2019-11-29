/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_count_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:52:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 11:08:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

size_t		ft_parse_count_word(const char *s)
{
	size_t		count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (*s)
			++count;
		while (!ft_isspace(*s))
			++s;
	}
	return (count);
}
