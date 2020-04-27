/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:20 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

static void		zeros_di(t_sub *sub)
{
	int		i;

	i = (sub->flags & 0x2 && sub->p == -1) ? 1 : 0;
	while (sub->s && (sub->s)[i] == ' ')
		(sub->s)[i++] = '0';
	if (i && ((sub->s)[i] == '-' || (sub->s)[i] == '+'))
	{
		(sub->s)[0] = (sub->s)[i];
		(sub->s)[i] = '0';
	}
}

static void		precision_di(t_sub *sub)
{
	if ((sub->s)[0] != '-' && (size_t)(sub->p) > ft_strlen(sub->s))
		sub->s = ft_strpad(&(sub->s), sub->p - ft_strlen(sub->s), sub->p, ' ');
	else if ((sub->s)[0] == '-' && (size_t)(sub->p) >= ft_strlen(sub->s))
		sub->s = ft_strpad(&(sub->s), sub->p - ft_strlen(sub->s) + 1, sub->p + 1, ' ');
	zeros_di(sub);
}

static void		flags_di(t_sub *sub)
{
	sub->s = ft_strpad(&(sub->s), 1, ft_strlen(sub->s) + 1, ' ');
	if (sub->flags & 0x4)
		(sub->s)[0] = '+';
}

static void		width_di(t_sub *sub)
{
	if ((size_t)(sub->j) > (size_t)(sub->w) - sub->len)
		sub->j = sub->w - sub->len;
	if (!((sub->flags) & 0x30))
		sub->j = sub->w - sub->j - sub->len;
	else if ((sub->flags & 0x30) == 0x30)
		sub->j = (sub->w - sub->len) / 2;
	else if ((sub->flags) & 0x20)
		sub->j = ((sub->w - sub->len) / 2) + (((sub->w - sub->len) % 2) ? 1 : 0);
	sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
	sub->len = ft_strlen(sub->s);
}

char			*crop_di(t_sub *sub)
{
	if (ft_strequ(sub->s, "0") && sub->flags & 0x4)
		sub->flags = sub->flags ^ 0x6;
	if (sub->p >= 0)
		precision_di(sub);
	if (sub->flags & 0x6 && (sub->s)[0] != '-')
		flags_di(sub);
	sub->len = ft_strlen(sub->s);
	if ((size_t)(sub->w) > sub->len)
		width_di(sub);
	if (sub->flags & 0x8 && !(sub->flags & 0x10) && sub->p == -1)
		zeros_di(sub);
	return (sub->s);
}
