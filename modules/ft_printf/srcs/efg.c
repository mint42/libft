/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:57:08 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:50:55 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

static void		zeros_efg(t_sub *sub)
{
	int		i;

	i = 0;
	while (S && S[i] == ' ')
		S[i++] = '0';
}

static void		flags_efg(t_sub *sub)
{
	S = ft_strpad(&S, 1, ft_strlen(S) + 1, ' ');
	if (FLAGS & 0x4)
		S[0] = '+';
}

static void		width_efg(t_sub *sub)
{
	if ((size_t)JUST > (size_t)WIDTH - LEN)
		JUST = WIDTH - LEN;
	if (!(FLAGS & 0x30))
		JUST = WIDTH - JUST - LEN;
	else if ((FLAGS & 0x30) == 0x30)
		JUST = (WIDTH - LEN) / 2;
	else if (FLAGS & 0x20)
		JUST = ((WIDTH - LEN) / 2) + (((WIDTH - LEN) % 2) ? 1 : 0);
	S = ft_strpad(&S, JUST, WIDTH, ' ');
	LEN = ft_strlen(S);
}

char			*crop_efg(t_sub *sub)
{
	if (FLAGS & 0x6 && S[0] != '-')
		flags_efg(sub);
	LEN = ft_strlen(S);
	if ((size_t)WIDTH > LEN)
		width_efg(sub);
	if (FLAGS & 0x8 && !(FLAGS & 0x10))
		zeros_efg(sub);
	if (TYPE & 0x1500000)
		S = ft_strupper(S);
	return (S);
}
