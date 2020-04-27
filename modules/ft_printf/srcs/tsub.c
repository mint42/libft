/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:04:22 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_printf_parse.h"
#include "ft_printf_fmt.h"
#include "ft_str.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include <stddef.h>

static char	*get_flags(char *fmt, t_sub *s)
{
	char	*spec;
	char	*cur;

	spec = "^-0+ #";
	while (*fmt && (cur = ft_strchr(spec, *fmt)) && ++fmt)
		s->flags = s->flags | (1 << (5 - (cur - spec)));
	return (fmt);
}

static char	*get_wjp(char *fmt, t_sub *s, va_list ap)
{
	int		*num;

	num = (*fmt == '.' && ++fmt) ? &(s->p) : &(s->w);
	if (!ft_isdigit(*fmt) && *fmt != '.' && *fmt != '*')
		return (fmt);
	while (num)
	{
		if (fmt && *fmt == '*' && fmt++)
			*num = va_arg(ap, int);
		else
		{
			*num = ft_atoi(fmt);
			while (fmt && ft_isdigit(*fmt))
				++fmt;
		}
		if (num == &(s->w) && *fmt == ':' && ++fmt)
			num = &(s->j);
		else
			num = (*fmt == '.' && num != &(s->p) && ++fmt) ? &(s->p) : 0;
	}
	return (fmt);
}

static char	*get_type(char *fmt, t_sub *s)
{
	char	*spec;
	char	*cur;

	spec = "lLhHjzgGeEfFcCsSdDiIbBoOuUxXpP%(";
	if (*fmt && (cur = ft_strchr(spec, *fmt)) && (cur - spec) < 6 && ++fmt)
		s->type = (s->type) | (1 << (31 - (cur - spec)));
	if (s->type & 0xA0000000 && (*fmt == 'l' || *fmt == 'h'))
		s->type = (*fmt++ == 'l') ? s->type ^ 0xC0000000 : s->type ^ 0x30000000;
	if (*fmt && (cur = ft_strchr(spec, *fmt)) && (cur - spec) >= 6 && ++fmt)
		s->type = s->type | (1 << (31 - (cur - spec)));
	if (s->type & 0x3F0FCC0)
		s->base = ((s->type) & 0xC00) ? 2 : 10;
	else if (s->type & 0x33C)
		s->base = (s->type & 0x300) ? 8 : 16;
	else if (s->type & 0x1 && (s->base = ft_atoi(fmt)) && s->base > 1
			&& s->base <= 36)
	{
		while (ft_isdigit(*fmt))
			++fmt;
	}
	if (s->type & 0x1 && *fmt == ')' && ++fmt && (*fmt == 'b' || *fmt == 'B'))
		s->type = (*fmt++ == 'b') ? s->type ^ 0x801 : s->type ^ 0x401;
	if (!(s->type & 0x3FFFFFE))
		s->type = 0;
	return (fmt);
}

static char	*get_sub(char *fmt, t_sub *s, va_list ap)
{
	if ((s->flags & 0x6 && (s->base != 10 || s->type & 0xC0 ||
				s->flags == 0x6)) ||
		(s->flags & 0x1 && (s->base != 8 && s->base != 16 &&
				s->base != 2)) ||
		(s->flags & 0x8 && s->type & 0xF000E) ||
		(s->type & 0xFC000000 && s->type & 0x5514E))
		s->type = 0;
	if (!(s->type))
		while (fmt && *fmt && ft_strchr(VALID_FMTS, *fmt))
			++fmt;
	if (s->w < 0)
	{
		s->flags = s->flags | 0x10;
		s->w = s->w * -1;
	}
	if (s->type)
		s->s = parse(s, ap);
	if (!(s->type) || !(s->s))
	{
		s->s = conv_utf8_str(L"¯\\_(ツ)_/¯", (s->s));
		s->len = 13;
	}
	return (fmt);
}

t_sub		make_tsub(char **fmt, va_list ap, int init)
{
	t_sub	sub;

	sub.s = 0;
	sub.len = 0;
	sub.type = 0;
	sub.base = 0;
	sub.p = -1;
	sub.w = 0;
	sub.j = 0;
	sub.flags = 0;
	if (init)
		return (sub);
	++(*fmt);
	*fmt = get_flags(*fmt, &sub);
	*fmt = get_wjp(*fmt, &sub, ap);
	*fmt = get_type(*fmt, &sub);
	*fmt = get_sub(*fmt, &sub, ap);
	return (sub);
}
