/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:25:26 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 14:26:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*cur;

	str = (char *)malloc(sizeof(char *) * len);
	cur = str;
	s = s + start;
	while (len--)
		*cur++ = *s++;
	*cur = '\0';
	return (sizeof(str) ? str : 0);
}
