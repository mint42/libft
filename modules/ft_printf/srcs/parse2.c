/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:44:19 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_printf_crop.h"
#include "ft_str.h"
#include "ft_conv.h"
#include <stdarg.h>
#include <stdlib.h>

char	*parse_unicode(t_sub *sub, va_list ap)
{
	if (sub->type == 0x40000 || sub->type == 0x80080000)
	{
		sub->s = conv_utf8_char(va_arg(ap, wchar_t), sub->s);
		if (*(sub->s) == '\0')
			sub->flags = sub->flags | 0x40;
	}
	else if (sub->type == 0x10000 || sub->type == 0x80020000)
	{
		sub->s = conv_utf8_str(va_arg(ap, wchar_t *), sub->s);
		if (!sub->s)
		{
			sub->s = ft_strdup("(null)");
			sub->flags = sub->flags | 0x40;
		}
	}
	return ((sub->s) ? crop_unicode(sub) : sub->s);
}

char	*parse_csp(t_sub *sub, va_list ap)
{
	if (sub->type == 0x2)
		sub->s = ft_strdup("%");
	else if (sub->type == 0x80000)
	{
		sub->s = ft_ctoa(va_arg(ap, int));
		if (*(sub->s) == '\0')
			sub->flags = sub->flags | 0x40;
	}
	else if (sub->type == 0x20000)
	{
		sub->s = va_arg(ap, char *);
		if (sub->s)
			sub->s = ft_strdup(sub->s);
		else
		{
			sub->s = ft_strdup("(null)");
			sub->flags = sub->flags | 0x40;
		}
	}
	return ((sub->s) ? crop_csp(sub) : sub->s);
}
