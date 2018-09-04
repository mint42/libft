/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:35:08 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/02 18:31:58 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s)
	{
		ft_strcpy(s, s1);
		ft_strcat(s, s2);
	}
	return (s);
}
