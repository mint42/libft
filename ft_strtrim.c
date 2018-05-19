/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:37:50 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/17 20:49:06 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char *) * ft_strlen(s) + 1);
	i = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i--;
	while (*s == '\t' || *s == '\n' || *s == ' ')
		s++;
	while (i--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (ptr - ft_strlen(ptr));
}
