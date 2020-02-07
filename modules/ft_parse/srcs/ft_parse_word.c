/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:52:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 13:08:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

char	*ft_parse_word(char **s, size_t *len)
{
	char	*word;

	if (!(*s))
		return (0);
	word = *s;
	*len = 0;
	while (!ft_isspace(**s))
		++(*len);
	*s = *s + *len;
	return (word);
}
