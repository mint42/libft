/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:25:58 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_str.h"

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
