/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:16:10 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/14 21:01:23 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char *) * ft_strlen(s1) + 1);
	while (*s1)
		*cpy++ = *s1++;
	*cpy = '\0';
	return (cpy - ft_strlen(s1));
}
