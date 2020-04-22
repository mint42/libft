/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftosn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 04:19:45 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:34:06 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv_float.h"
#include "ft_str.h"
#include "ft_math.h"
#include "ft_utils.h"

static void		nbrcpy_p(long n, int precision, char *s)
{
	long int	multiplier;
	int			len;
	int			i;

	len = ft_numlen(n);
	i = 0;
	multiplier = ft_pow(10, len - 1);
	while (s[i] && i < precision)
	{
		if (i < (precision - len))
			s[i] = '0';
		else
		{
			s[i] = ((n / multiplier) % 10) * ((n < 0) ? -1 : 1) + '0';
			multiplier = multiplier / 10;
		}
		++i;
	}
}

static t_fp		get_parts(double n, int *exponent, int precision)
{
	t_fp	f;
	int		len;

	if (precision > 15)
		precision = 15;
	len = ft_numlen((long)n);
	while (n && (n > (1UL << 63) || len != precision + 1))
	{
		if (n > (1UL << 63) || len > precision + 1)
		{
			n = n / 10;
			++(*exponent);
		}
		else
		{
			n = n * 10;
			--(*exponent);
		}
		len = ft_numlen((long)n);
	}
	f.integer = ft_round(n) / ft_pow(10, precision);
	f.fraction = ft_round(n) - (f.integer * (long)ft_pow(10, precision));
	if (n)
		*exponent = *exponent + precision;
	return (f);
}

static char		*make_string(t_fp f, int sign, int exponent, int precision)
{
	char	*s;
	char	*cur;

	s = ft_strinit('0', sign + 3 + ((precision) ? precision + 1 : 0) +
		((ft_numlen(exponent) < 2) ? 2 : ft_numlen(exponent)));
	cur = s;
	if (sign)
		*cur++ = '-';
	*cur++ = f.integer + '0';
	if (precision)
	{
		*cur++ = '.';
		if (precision > 15)
			nbrcpy_p(f.fraction, 15, cur);
		else
			nbrcpy_p(f.fraction, precision, cur);
	}
	if (exponent >= 0)
		ft_strncpy(s + sign + ((precision) ? precision + 1 : 0) + 1, "e+", 2);
	else
		ft_strncpy(s + sign + ((precision) ? precision + 1 : 0) + 1, "e-", 2);
	cur = s + ft_strlen(s) - ft_numlen(exponent);
	nbrcpy_p(exponent, ft_numlen(exponent), cur);
	return (s);
}

char			*ft_ftosn(double n, int precision)
{
	t_double	doub;
	t_fp		f;
	int			sign;
	int			exponent;
	long		significand;

	doub.d = n;
	sign = (doub.l >> 63) & 1;
	exponent = ((doub.l >> 52) & 0x7ff);
	significand = (doub.l & 0x000fffffffffffff);
	if (exponent == 0x7ff)
	{
		if (significand)
			return (ft_strdup("nan"));
		else
			return (ft_strdup((sign) ? "-inf" : "inf"));
	}
	exponent = 0;
	f = get_parts(ft_absd(n), &exponent, precision);
	return (make_string(f, sign, exponent, precision));
}
