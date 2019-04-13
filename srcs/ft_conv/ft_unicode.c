/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:52:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_conv.h"

/*
**	08	11000011 10111111
**	09	11000111 10111111
**	10	11001111 10111111
**	11	11011111 10111111
**
**	12  11100000 10111111 10111111
**	13	11100001 10111111 10111111
**	14	11100011 10111111 10111111
**	15	11100111 10111111 10111111
**	16	11101111 10111111 10111111
**
**	17	11110000 10011111 10111111 10111111
**	18	11110000 10111111 10111111 10111111
**	19	11110001 10111111 10111111 10111111
**	20	11110011 10111111 10111111 10111111
**	21	11110111 10111111 10111111 10111111
**
**	bytes = (bits + 3) / 5
*/

static int	get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

char		*conv_utf8_char(wchar_t wc, char *s)
{
	char	*cur;
	int		bytes;

	bytes = get_bytes(wc);
	if (!s && wc)
		s = ft_strnew(bytes);
	if (!wc || !s)
		return ((!wc) ? ft_strnew(1) : 0);
	cur = s + bytes - 1;
	if (bytes > 1)
		while (cur >= s)
		{
			*cur = *cur | (!(cur - s) ? (0xFF << (8 - bytes)) : 0x80);
			*cur = *cur | (wc & 0x3F);
			wc = wc >> 6;
			cur = (cur - s) ? (cur - 1) : 0;
		}
	else
		*cur = (char)wc;
	return (s);
}

char		*conv_utf8_str(wchar_t *ws, char *s)
{
	int		bytes;
	int		totalbytes;

	totalbytes = 0;
	if (!ws)
		return (0);
	while (ws && *ws)
		totalbytes = totalbytes + get_bytes(*ws++);
	s = ft_strnew(totalbytes);
	s = s + totalbytes;
	while (totalbytes)
	{
		--ws;
		bytes = get_bytes(*ws);
		totalbytes = totalbytes - bytes;
		s = s - bytes;
		s = conv_utf8_char(*ws, s);
	}
	return (s);
}
