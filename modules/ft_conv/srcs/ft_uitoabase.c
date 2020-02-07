/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:15:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_uitoabase(unsigned long long int n, int base)
{
	unsigned int			i;
	unsigned long long int	pow;
	char					*str;

	i = 1;
	pow = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (pow >= (unsigned long long int)base && ++i)
		pow /= base;
	str = ft_strnew(i);
	while (i-- > 0)
	{
		str[i] = (n % base) + ((base > 10) && (n % base > 9) ? 'a' - 10 : '0');
		n = n / base;
	}
	return (str);
}
