/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:44 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_conv.h"
#include "ft_str.h"
#include <stddef.h>

static void		precision_unicode(t_sub *sub)
{
	int		i;

	i = 0;
	if (sub->flags & 0x40 && sub->p < 6)
		(sub->s)[0] = '\0';
	while ((sub->s)[i] != '\0' && sub->p)
	{
		++i;
		while ((sub->s)[i] && ((sub->s)[i] & 0xC0) == 0x80)
			++i;
		--(sub->p);
	}
	(sub->s)[i] = '\0';
}

static void		width_unicode(t_sub *sub)
{
	if ((size_t)(sub->j) > (size_t)(sub->w) - sub->len)
		sub->j = sub->w - sub->len;
	if (!(sub->flags & 0x30))
		sub->j = sub->w - sub->j - sub->len;
	else if (((sub->flags) & 0x30) == 0x30)
		sub->j = (sub->w - sub->len) / 2;
	else if (sub->flags & 0x20)
		sub->j = ((sub->w - sub->len) / 2) + (((sub->w - sub->len) % 2) ? 1 : 0);
	if (sub->type & 0xC0000 && sub->flags & 0x40)
	{
		sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
		(sub->s)[(sub->j)] = '\0';
	}
	else
		sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
	sub->len = sub->w;
}

char			*crop_unicode(t_sub *sub)
{
	int		i;

	i = 0;
	if (sub->p >= 0 && !(sub->type & 0x40000))
		precision_unicode(sub);
	while ((sub->s)[i] && ++i)
		while ((sub->s)[i] && ((sub->s)[i] & 0xC0) == 0x80 && ++i)
			++(sub->w);
	sub->len = (sub->type & 0x40000 && sub->flags & 0x40) ? 1 : ft_strlen(sub->s);
	if ((size_t)(sub->w) > sub->len)
		width_unicode(sub);
	return (sub->s);
}
