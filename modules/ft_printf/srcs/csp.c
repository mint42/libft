/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:30:33 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:50:55 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_str.h"

char	*crop_csp(t_sub *sub)
{
	if (((size_t)PREC < ft_strlen(S)) && !(TYPE & 0x40002))
		S[((FLAGS & 0x40) ? 0 : PREC)] = '\0';
	LEN = (TYPE & 0x80000 && FLAGS & 0x40) ? 1 : ft_strlen(S);
	if ((size_t)WIDTH > LEN)
	{
		if ((size_t)JUST > (size_t)WIDTH - LEN)
			JUST = WIDTH - LEN;
		if (!(FLAGS & 0x30))
			JUST = WIDTH - JUST - LEN;
		else if ((FLAGS & 0x30) == 0x30)
			JUST = (WIDTH - LEN) / 2;
		else if (FLAGS & 0x20)
			JUST = ((WIDTH - LEN) / 2) + (((WIDTH - LEN) % 2) ? 1 : 0);
		if (TYPE & 0xC0000 && FLAGS & 0x40)
		{
			S = ft_strpad(&S, JUST, WIDTH, ' ');
			S[JUST] = '\0';
		}
		else
			S = ft_strpad(&S, JUST, WIDTH, ' ');
		LEN = WIDTH;
	}
	return (S);
}
