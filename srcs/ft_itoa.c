/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:25:58 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/06 21:00:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	num;

	num = (long)n;
	n = (int)ft_numlen(num) - 1;
	s = ft_strnew(ft_numlen(num));
	if (num < 0 && s)
	{
		s[0] = '-';
		num = num * -1;
	}
	while (n >= 0 && s && s[n] != '-')
	{
		s[n] = (num % 10) + 48;
		num = num / 10;
		--n;
	}
	return (s);
}
