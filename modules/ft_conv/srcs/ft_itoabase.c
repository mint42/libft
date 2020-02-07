/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:15:31 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_itoabase(long long int n, int base)
{
	long long int	pow;
	int				sign;
	int				i;
	char			*str;

	i = 1;
	sign = (base == 10 && n < 0) ? 1 : 0;
	if (n == 0 || n < -9223372036854775807)
		return (n ? ft_strdup("-9223372036854775808") : ft_strdup("0"));
	if (sign)
		++i;
	n = (n < 0) ? n * -1 : n;
	pow = n;
	while (pow >= (long long)base && ++i)
		pow /= base;
	str = ft_strnew(i + sign);
	while (i-- > 0)
	{
		str[i] = (n % base) + ((base > 10) && (n % base > 9) ? 'a' - 10 : '0');
		n = n / base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
