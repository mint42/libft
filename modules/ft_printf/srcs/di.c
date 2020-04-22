/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:20 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:50:55 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

static void		zeros_di(t_sub *sub)
{
	int		i;

	i = (FLAGS & 0x2 && PREC == -1) ? 1 : 0;
	while (S && S[i] == ' ')
		S[i++] = '0';
	if (i && (S[i] == '-' || S[i] == '+'))
	{
		S[0] = S[i];
		S[i] = '0';
	}
}

static void		precision_di(t_sub *sub)
{
	if (S[0] != '-' && (size_t)PREC > ft_strlen(S))
		S = ft_strpad(&S, PREC - ft_strlen(S), PREC, ' ');
	else if (S[0] == '-' && (size_t)PREC >= ft_strlen(S))
		S = ft_strpad(&S, PREC - ft_strlen(S) + 1, PREC + 1, ' ');
	zeros_di(sub);
}

static void		flags_di(t_sub *sub)
{
	S = ft_strpad(&S, 1, ft_strlen(S) + 1, ' ');
	if (FLAGS & 0x4)
		S[0] = '+';
}

static void		width_di(t_sub *sub)
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

char			*crop_di(t_sub *sub)
{
	if (ft_strequ(S, "0") && FLAGS & 0x4)
		FLAGS = FLAGS ^ 0x6;
	if (PREC >= 0)
		precision_di(sub);
	if (FLAGS & 0x6 && S[0] != '-')
		flags_di(sub);
	LEN = ft_strlen(S);
	if ((size_t)WIDTH > LEN)
		width_di(sub);
	if (FLAGS & 0x8 && !(FLAGS & 0x10) && PREC == -1)
		zeros_di(sub);
	return (S);
}
