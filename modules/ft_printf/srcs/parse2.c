/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:44:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 17:49:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "crop.h"
#include "ft_str.h"
#include "ft_conv.h"
#include <stdarg.h>
#include <stdlib.h>

char	*parse_unicode(t_sub *sub, va_list ap)
{
	if (TYPE == 0x40000 || TYPE == 0x80080000)
	{
		S = conv_utf8_char(va_arg(ap, wchar_t), S);
		if (*S == '\0')
			FLAGS = FLAGS | 0x40;
	}
	else if (TYPE == 0x10000 || TYPE == 0x80020000)
	{
		S = conv_utf8_str(va_arg(ap, wchar_t *), S);
		if (!S)
		{
			S = ft_strdup("(null)");
			FLAGS = FLAGS | 0x40;
		}
	}
	return ((S) ? crop_unicode(sub) : S);
}

char	*parse_csp(t_sub *sub, va_list ap)
{
	if (TYPE == 0x2)
		S = ft_strdup("%");
	else if (TYPE == 0x80000)
	{
		S = ft_ctoa(va_arg(ap, int));
		if (*S == '\0')
			FLAGS = FLAGS | 0x40;
	}
	else if (TYPE == 0x20000)
	{
		S = va_arg(ap, char *);
		if (S)
			S = ft_strdup(S);
		else
		{
			S = ft_strdup("(null)");
			FLAGS = FLAGS | 0x40;
		}
	}
	return ((S) ? crop_csp(sub) : S);
}
