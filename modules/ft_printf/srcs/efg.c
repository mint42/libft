/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:57:08 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:28:11 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

static void		zeros_efg(t_sub *sub)
{
	int		i;

	i = 0;
	while (sub->s && (sub->s)[i] == ' ')
		(sub->s)[i++] = '0';
}

static void		flags_efg(t_sub *sub)
{
	sub->s = ft_strpad(&(sub->s), 1, ft_strlen(sub->s) + 1, ' ');
	if (sub->flags & 0x4)
		(sub->s)[0] = '+';
}

static void		width_efg(t_sub *sub)
{
	if ((size_t)(sub->j) > (size_t)(sub->w) - sub->len)
		sub->j = sub->w - sub->len;
	if (!((sub->flags) & 0x30))
		sub->j = sub->w - sub->j - sub->len;
	else if (((sub->flags) & 0x30) == 0x30)
		sub->j = (sub->w - sub->len) / 2;
	else if ((sub->flags) & 0x20)
		sub->j = ((sub->w - sub->len) / 2) + (((sub->w - sub->len) % 2) ? 1 : 0);
	sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
	sub->len = ft_strlen(sub->s);
}

char			*crop_efg(t_sub *sub)
{
	if (sub->flags & 0x6 && (sub->s)[0] != '-')
		flags_efg(sub);
	sub->len = ft_strlen(sub->s);
	if ((size_t)(sub->w) > sub->len)
		width_efg(sub);
	if (sub->flags & 0x8 && !(sub->flags & 0x10))
		zeros_efg(sub);
	if (sub->type & 0x1500000)
		(sub->s) = ft_strupper(sub->s);
	return (sub->s);
}
