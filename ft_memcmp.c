/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 22:20:54 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/17 17:01:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cur;
	unsigned char *cur2;

	cur = (unsigned char *)s1;
	cur2 = (unsigned char *)s2;
	while (n-- && *cur++ == *cur2++)
		;
	return (cur - cur2);
}
