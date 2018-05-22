/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:02:35 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/21 18:40:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, int c)
{
	char	**str;
	int		i;
	int		j;

	str = (char **)malloc(sizeof(char **) * ft_strlen(s));
	i = 0;
	j = 0;
	while (*s++)
	{
		while (*s != (char)c && *s)
			str[i][j++] = *s++;
		i++;
	}
}
