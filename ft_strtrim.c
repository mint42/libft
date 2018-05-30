/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:37:50 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 14:25:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	char	*cur;
	int		i;

	str = (char *)malloc(sizeof(char *) * ft_strlen(s) + 1);
	cur = str;
	i = ft_strlen(s) - 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i--;
	while (*s == '\t' || *s == '\n' || *s == ' ')
		s++;
	while (i--)
		*cur++ = *s++;
	*cur = '\0';
	return (sizeof(str) ? str : 0);
}
