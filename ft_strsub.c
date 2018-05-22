/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:25:26 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/21 18:15:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	
	ptr = (char *)malloc(sizeof(char *) * len);
	s = s + start;
	while (len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (sizeof(ptr) ? ptr - ft_strlen(ptr) : 0);
}
