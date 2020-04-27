/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:33 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:56:38 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

char	*crop_csp(t_sub *sub)
{
	if (((size_t)(sub->p) < ft_strlen(sub->s)) && !(sub->type & 0x40002))
		(sub->s)[((sub->flags & 0x40) ? 0 : sub->p)] = '\0';
	sub->len = (sub->type & 0x80000 && sub->flags & 0x40) ? 1 : ft_strlen(sub->s);
	if ((size_t)(sub->w) > sub->len)
	{
		if ((size_t)(sub->j) > (size_t)(sub->w) - sub->len)
			sub->j = sub->w - sub->len;
		if (!(sub->flags & 0x30))
			sub->j = sub->w - sub->j - sub->len;
		else if ((sub->flags & 0x30) == 0x30)
			sub->j = (sub->w - sub->len) / 2;
		else if (sub->flags & 0x20)
			sub->j = ((sub->w - sub->len) / 2) + (((sub->w - sub->len) % 2) ? 1 : 0);
		if (sub->type & 0xC0000 && sub->flags & 0x40)
		{
			sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
			(sub->s)[sub->j] = '\0';
		}
		else
			sub->s = ft_strpad(&(sub->s), sub->j, sub->w, ' ');
		sub->len = sub->w;
	}
	return (sub->s);
}
