/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:02:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 13:10:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"
#include "ft_utils.h"

static int	count_words(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != (unsigned char)c)
		{
			++i;
			while (*s && *s != (unsigned char)c)
				++s;
		}
		else
			++s;
	}
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		wc;

	if (!s)
		return (0);
	i = 0;
	wc = count_words(s, (int)c);
	str = (char **)ft_memalloc(sizeof(char *) * (wc + 1));
	while (wc-- && str)
	{
		while (*s && *s == c)
			++s;
		str[i] = ft_strsub(s, 0, ft_strlend(s, c));
		if (!str[i])
			return (0);
		s = s + ft_strlend(s, (int)c);
		++i;
		str[i] = 0;
	}
	return (str);
}
