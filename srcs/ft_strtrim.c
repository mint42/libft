/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:37:50 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/06 19:51:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;

	if (!s)
		return (0);
	i = ft_strlen(s) - 1;
	j = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		--i;
	while (s[j] == '\t' || s[j] == '\n' || s[j] == ' ')
		++j;
	return (j < i ? ft_strsub(s, j, i - j + 1) : ft_strnew(0));
}
