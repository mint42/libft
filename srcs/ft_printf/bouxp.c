/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bouxp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:37:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

static void		zeros_bouxp(t_sub *sub)
{
	int		i;

	i = 0;
	while (S && S[i] == ' ')
		S[i++] = '0';
	if (i && S[i] == '0' && S[++i] && (S[i] == 'x' || S[i] == 'b'))
	{
		S[1] = S[i];
		S[i] = '0';
	}
}

static void		precision_bouxp(t_sub *sub)
{
	S = ft_strpad(&S, PREC - ft_strlen(S), PREC, ' ');
	zeros_bouxp(sub);
}

static void		flags_bouxp(t_sub *sub)
{
	if (BASE == 8)
		S = ft_strpad(&S, 1, ft_strlen(S) + 1, ' ');
	else
	{
		S = ft_strpad(&S, 2, ft_strlen(S) + 2, ' ');
		S[1] = (BASE == 2) ? 'b' : 'x';
	}
	S[0] = '0';
}

static void		width_bouxp(t_sub *sub)
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

char			*crop_bouxp(t_sub *sub)
{
	if (ft_strequ(S, "0") && FLAGS & 0x1)
		FLAGS = FLAGS & 0x28;
	if (PREC > (int)ft_strlen(S))
		precision_bouxp(sub);
	if (FLAGS & 0x1 || TYPE & 0xC)
		flags_bouxp(sub);
	LEN = ft_strlen(S);
	if ((size_t)WIDTH > LEN)
		width_bouxp(sub);
	if (FLAGS & 0x8 && !(FLAGS & 0x10) && PREC == -1)
		zeros_bouxp(sub);
	if (TYPE & 0x414)
		S = ft_strupper(S);
	return (S);
}
