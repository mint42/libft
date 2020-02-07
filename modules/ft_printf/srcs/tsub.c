/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:04:22 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:38:57 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse.h"
#include "ft_str.h"
#include "ft_utils.h"
#include "ft_conv.h"
#include <stddef.h>

static char	*get_flags(char *fmt, t_sub *sub)
{
	char	*spec;
	char	*cur;

	FLAGS = 0;
	spec = "^-0+ #";
	while (*fmt && (cur = ft_strchr(spec, *fmt)) && ++fmt)
		FLAGS = FLAGS | (1 << (5 - (cur - spec)));
	return (fmt);
}

static char	*get_wjp(char *fmt, t_sub *sub, va_list ap)
{
	int		*num;

	PREC = -1;
	WIDTH = 0;
	JUST = 0;
	num = (*fmt == '.' && ++fmt) ? &PREC : &WIDTH;
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
		if (num == &WIDTH && *fmt == ':' && ++fmt)
			num = &JUST;
		else
			num = (*fmt == '.' && num != &PREC && ++fmt) ? &PREC : 0;
	}
	return (fmt);
}

static char	*get_type(char *fmt, t_sub *sub)
{
	char	*spec;
	char	*cur;

	TYPE = 0;
	BASE = 0;
	spec = "lLhHjzgGeEfFcCsSdDiIbBoOuUxXpP%(";
	if (*fmt && (cur = ft_strchr(spec, *fmt)) && (cur - spec) < 6 && ++fmt)
		TYPE = TYPE | (1 << (31 - (cur - spec)));
	if (TYPE & 0xA0000000 && (*fmt == 'l' || *fmt == 'h'))
		TYPE = (*fmt++ == 'l') ? TYPE ^ 0xC0000000 : TYPE ^ 0x30000000;
	if (*fmt && (cur = ft_strchr(spec, *fmt)) && (cur - spec) >= 6 && ++fmt)
		TYPE = TYPE | (1 << (31 - (cur - spec)));
	if (TYPE & 0x3F0FCC0)
		BASE = (TYPE & 0xC00) ? 2 : 10;
	else if (TYPE & 0x33C)
		BASE = (TYPE & 0x300) ? 8 : 16;
	else if (TYPE & 0x1 && (BASE = ft_atoi(fmt)) && BASE > 1 && BASE <= 36)
		while (ft_isdigit(*fmt))
			++fmt;
	if (TYPE & 0x1 && *fmt == ')' && ++fmt && (*fmt == 'b' || *fmt == 'B'))
		TYPE = (*fmt++ == 'b') ? TYPE ^ 0x801 : TYPE ^ 0x401;
	if (!(TYPE & 0x3FFFFFE))
		TYPE = 0;
	return (fmt);
}

static char	*get_sub(char *fmt, t_sub *sub, va_list ap)
{
	if ((FLAGS & 0x6 && (BASE != 10 || TYPE & 0xC0 || FLAGS == 0x6)) ||
		(FLAGS & 0x1 && (BASE != 8 && BASE != 16 && BASE != 2)) ||
		(FLAGS & 0x8 && TYPE & 0xF000E) ||
		(TYPE & 0xFC000000 && TYPE & 0x5514E))
		TYPE = 0;
	if (!TYPE)
		while (fmt && *fmt && ft_strchr(VALID_FMTS, *fmt))
			++fmt;
	if (WIDTH < 0)
	{
		FLAGS = FLAGS | 0x10;
		WIDTH = WIDTH * -1;
	}
	if (TYPE)
		S = parse(sub, ap);
	if (!TYPE || !S)
	{
		S = conv_utf8_str(L"¯\\_(ツ)_/¯", S);
		LEN = 13;
	}
	return (fmt);
}

t_sub		make_tsub(char **fmt, va_list ap, int init)
{
	t_sub	sub;

	sub.s = 0;
	sub.len = 0;
	if (init)
		return (sub);
	++(*fmt);
	*fmt = get_flags(*fmt, &sub);
	*fmt = get_wjp(*fmt, &sub, ap);
	*fmt = get_type(*fmt, &sub);
	*fmt = get_sub(*fmt, &sub, ap);
	return (sub);
}
