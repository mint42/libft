/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:02:35 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 11:16:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		w;
	int		i;

	w = 0;
	i = 0;
	str = (char **)malloc(sizeof(char *) * ft_strlen(s));
	while (*s && sizeof(str) > 0)
	{
		while(*s == c)
			s++;
		if (i)
			w++;
		i = 0;
		while (*s != c && *s)
			str[w][i++] = *s++;
		str[w][i] = '\0';
	}
	return (sizeof(str) ? str : 0);
}
