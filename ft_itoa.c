/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:25:58 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 14:46:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	long	c;

	str = (char *)malloc(sizeof(char *) * 12);
	num = (long)n;
	n = 0;
	c = 1000000000;
	if (num < 0 && ++n)
	{
		*str++ = '-';
		num *= -1;
	}
	while (c)
	{
		if (num / c && ++n)
		{
			*str++ = ((num / c) + 48);
			num = num % c;
		}
		c /= 10;
	}
	*str = '\0';
	return (str - n);
}
