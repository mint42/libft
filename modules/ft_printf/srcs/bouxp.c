/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouxp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:08 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

static void		zeros_bouxp(t_sub *sub)
{
	int		i;

	i = 0;
	while (sub->s && (sub->s)[i] == ' ')
		(sub->s)[i++] = '0';
	if (i && (sub->s)[i] == '0' &&
			(sub->s)[++i] && ((sub->s)[i] == 'x' || (sub->s)[i] == 'b'))
	{
		(sub->s)[1] = (sub->s)[i];
		(sub->s)[i] = '0';
	}
}

static void		precision_bouxp(t_sub *sub)
{
	sub->s = ft_strpad(&(sub->s), sub->p - ft_strlen(sub->s), sub->p, ' ');
	zeros_bouxp(sub);
}

static void		flags_bouxp(t_sub *sub)
{
	if (sub->base == 8)
		sub->s = ft_strpad(&(sub->s), 1, ft_strlen(sub->s) + 1, ' ');
	else
	{
		(sub->s) = ft_strpad(&(sub->s), 2, ft_strlen(sub->s) + 2, ' ');
		(sub->s)[1] = (sub->base == 2) ? 'b' : 'x';
	}
	(sub->s)[0] = '0';
}

static void		width_bouxp(t_sub *sub)
{
	if ((size_t)(sub->j) > (size_t)(sub->w) - sub->len)
		sub->j = sub->w - sub->len;
	if (!(sub->flags & 0x30))
		sub->j = sub->w - sub->j - sub->len;
	else if ((sub->flags & 0x30) == 0x30)
		sub->j = (sub->w - sub->len) / 2;
	else if (sub->flags & 0x20)
		sub->j = ((sub->w - sub->len) / 2) + (((sub->w - sub->len) % 2) ? 1 : 0);
	sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
	sub->len = ft_strlen(sub->s);
}

char			*crop_bouxp(t_sub *sub)
{
	if (ft_strequ(sub->s, "0") && sub->flags & 0x1)
		sub->flags = sub->flags & 0x28;
	if (sub->p > (int)ft_strlen(sub->s))
		precision_bouxp(sub);
	if (sub->flags & 0x1 || sub->type & 0xC)
		flags_bouxp(sub);
	sub->len = ft_strlen(sub->s);
	if ((size_t)(sub->w) > sub->len)
		width_bouxp(sub);
	if (sub->flags & 0x8 && !(sub->flags & 0x10) && sub->p == -1)
		zeros_bouxp(sub);
	if (sub->type & 0x414)
		(sub->s) = ft_strupper(sub->s);
	return (sub->s);
}
