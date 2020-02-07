/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:22:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	char	*cur;

	cur = s1 + ft_strlen(s1);
	while (len-- && *s2)
		*cur++ = *s2++;
	*cur = '\0';
	return (s1);
}
