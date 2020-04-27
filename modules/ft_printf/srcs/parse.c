/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:27:43 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_printf_parse.h"
#include "ft_printf_crop.h"
#include "ft_conv.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

char	*parse_efg(t_sub *sub, va_list ap)
{
	if (sub->p == -1)
		sub->p = 6;
	if (sub->type & 0x300000)
	{
		if (!(sub->type & 0xFC000000) || sub->type & 0x80000000)
			sub->s = ft_ftoa(va_arg(ap, double), sub->p);
		else if (sub->type & 0x40000000)
			sub->s = ft_ftoa(va_arg(ap, long double), sub->p);
	}
	else if (sub->type & 0xC00000)
	{
		if (!(sub->type & 0xFC000000) || sub->type & 0x80000000)
			sub->s = ft_ftosn(va_arg(ap, double), sub->p);
		else if (sub->type & 0x40000000)
			sub->s = ft_ftosn(va_arg(ap, long double), sub->p);
	}
	return ((sub->s) ? crop_efg(sub) : sub->s);
}

char	*parse_di(t_sub *sub, va_list ap)
{
	if (sub->type & 0x20000000)
		sub->s = ft_itoabase((short)va_arg(ap, int), sub->base);
	else if (sub->type & 0x10000000)
		sub->s = ft_itoabase((char)va_arg(ap, int), sub->base);
	else if (sub->type & 0x80005000)
		sub->s = ft_itoabase(va_arg(ap, long int), sub->base);
	else if (sub->type & 0x40000000)
		sub->s = ft_itoabase(va_arg(ap, long long int), sub->base);
	else if (sub->type & 0x8000000)
		sub->s = ft_itoabase(va_arg(ap, intmax_t), sub->base);
	else if (sub->type & 0x4000000)
		sub->s = ft_itoabase(va_arg(ap, size_t), sub->base);
	else if (!(sub->type & 0xFC000000))
		sub->s = ft_itoabase(va_arg(ap, int), sub->base);
	return ((sub->s) ? crop_di(sub) : sub->s);
}

char	*parse_bouxp(t_sub *sub, va_list ap)
{
	if (sub->type & 0x20000000)
		sub->s = ft_uitoabase((unsigned short)va_arg(ap, int), sub->base);
	else if (sub->type & 0x10000000)
		sub->s = ft_uitoabase((uint8_t)va_arg(ap, int), sub->base);
	else if (sub->type & 0x80000140)
		sub->s = ft_uitoabase(va_arg(ap, unsigned long int), sub->base);
	else if (sub->type & 0x4000000C)
		sub->s = ft_uitoabase(va_arg(ap, unsigned long long int), sub->base);
	else if (sub->type & 0x8000000)
		sub->s = ft_uitoabase(va_arg(ap, uintmax_t), sub->base);
	else if (sub->type & 0x4000000)
		sub->s = ft_uitoabase(va_arg(ap, size_t), sub->base);
	else if (!(sub->type & 0xFC000000))
		sub->s = ft_uitoabase(va_arg(ap, unsigned int), sub->base);
	return (sub->s ? crop_bouxp(sub) : sub->s);
}

char	*parse(t_sub *sub, va_list ap)
{
	if ((sub->type) & 0xF000 || ((sub->type) & 0xC00 && (sub->base) == 10))
		sub->s = parse_di(sub, ap);
	else if ((sub->type) & 0x0FFC)
		sub->s = parse_bouxp(sub, ap);
	else if ((sub->type) & 0xA0002 && !((sub->type) & 0xFC000000))
		sub->s = parse_csp(sub, ap);
	else if ((sub->type) & 0xF0000)
		sub->s = parse_unicode(sub, ap);
	else if ((sub->type) & 0x3F00000)
		sub->s = parse_efg(sub, ap);
	return ((sub->s));
}
