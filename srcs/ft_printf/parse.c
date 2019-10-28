/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:27:43 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 17:49:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"
#include "crop.h"
#include "ft_conv.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

char	*parse_efg(t_sub *sub, va_list ap)
{
	if (PREC == -1)
		PREC = 6;
	if (TYPE & 0x300000)
	{
		if (!(TYPE & 0xFC000000) || TYPE & 0x80000000)
			S = ft_ftoa(va_arg(ap, double), PREC);
		else if (TYPE & 0x40000000)
			S = ft_ftoa(va_arg(ap, long double), PREC);
	}
	else if (TYPE & 0xC00000)
	{
		if (!(TYPE & 0xFC000000) || TYPE & 0x80000000)
			S = ft_ftosn(va_arg(ap, double), PREC);
		else if (TYPE & 0x40000000)
			S = ft_ftosn(va_arg(ap, long double), PREC);
	}
	return ((S) ? crop_efg(sub) : S);
}

char	*parse_di(t_sub *sub, va_list ap)
{
	if (TYPE & 0x20000000)
		S = ft_itoabase((short)va_arg(ap, int), BASE);
	else if (TYPE & 0x10000000)
		S = ft_itoabase((char)va_arg(ap, int), BASE);
	else if (TYPE & 0x80005000)
		S = ft_itoabase(va_arg(ap, long int), BASE);
	else if (TYPE & 0x40000000)
		S = ft_itoabase(va_arg(ap, long long int), BASE);
	else if (TYPE & 0x8000000)
		S = ft_itoabase(va_arg(ap, intmax_t), BASE);
	else if (TYPE & 0x4000000)
		S = ft_itoabase(va_arg(ap, size_t), BASE);
	else if (!(TYPE & 0xFC000000))
		S = ft_itoabase(va_arg(ap, int), BASE);
	return ((S) ? crop_di(sub) : S);
}

char	*parse_bouxp(t_sub *sub, va_list ap)
{
	if (TYPE & 0x20000000)
		S = ft_uitoabase((unsigned short)va_arg(ap, int), BASE);
	else if (TYPE & 0x10000000)
		S = ft_uitoabase((uint8_t)va_arg(ap, int), BASE);
	else if (TYPE & 0x80000140)
		S = ft_uitoabase(va_arg(ap, unsigned long int), BASE);
	else if (TYPE & 0x4000000C)
		S = ft_uitoabase(va_arg(ap, unsigned long long int), BASE);
	else if (TYPE & 0x8000000)
		S = ft_uitoabase(va_arg(ap, uintmax_t), BASE);
	else if (TYPE & 0x4000000)
		S = ft_uitoabase(va_arg(ap, size_t), BASE);
	else if (!(TYPE & 0xFC000000))
		S = ft_uitoabase(va_arg(ap, unsigned int), BASE);
	return ((S) ? crop_bouxp(sub) : S);
}

char	*parse(t_sub *sub, va_list ap)
{
	if (TYPE & 0xF000 || (TYPE & 0xC00 && BASE == 10))
		S = parse_di(sub, ap);
	else if (TYPE & 0x0FFC)
		S = parse_bouxp(sub, ap);
	else if (TYPE & 0xA0002 && !(TYPE & 0xFC000000))
		S = parse_csp(sub, ap);
	else if (TYPE & 0xF0000)
		S = parse_unicode(sub, ap);
	else if (TYPE & 0x3F00000)
		S = parse_efg(sub, ap);
	return (S);
}
