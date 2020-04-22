/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 14:30:34 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:50:55 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tsub.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

static char		*clean(char *s, t_sub sub, char **fmt, size_t *slen)
{
	size_t	d;

	if (!s)
	{
		d = ft_strlend(*fmt, '%');
		*slen = d;
		return (ft_strncpy(ft_strnew(d), *fmt, d));
	}
	d = ft_strlend(*fmt, '%');
	s = ft_stresize(&s, 0, *slen + sub.len + d);
	s = (char *)ft_memcat(s, sub.s, *slen, sub.len);
	*slen = *slen + sub.len;
	s = ft_memcat(s, *fmt, *slen, d);
	*slen = *slen + d;
	ft_strdel(&(sub.s));
	return (s);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*s;
	t_sub		sub;
	size_t		slen;

	va_start(ap, fmt);
	slen = 0;
	s = clean(0, make_tsub((char **)&fmt, ap, 1), (char **)&fmt, &slen);
	while (fmt && *fmt)
	{
		if (!(fmt = ft_strchr((char *)fmt, '%')))
			break ;
		sub = make_tsub((char **)&fmt, ap, 0);
		s = clean(s, sub, (char **)&fmt, &slen);
	}
	va_end(ap);
	write(STDOUT_FILENO, s, slen);
	ft_strdel(&s);
	return (slen);
}

int				ft_sprintf(char **s, const char *fmt, ...)
{
	va_list		ap;
	t_sub		sub;
	size_t		slen;

	va_start(ap, fmt);
	slen = 0;
	*s = clean(0, make_tsub((char **)&fmt, ap, 1), (char **)&fmt, &slen);
	while (fmt && *fmt)
	{
		if (!(fmt = ft_strchr((char *)fmt, '%')))
			break ;
		sub = make_tsub((char **)&fmt, ap, 0);
		*s = clean(*s, sub, (char **)&fmt, &slen);
	}
	va_end(ap);
	return (slen);
}

int				ft_printfd(int fd, const char *fmt, ...)
{
	va_list		ap;
	char		*s;
	t_sub		sub;
	size_t		slen;

	va_start(ap, fmt);
	slen = 0;
	s = clean(0, make_tsub((char **)&fmt, ap, 1), (char **)&fmt, &slen);
	while (fmt && *fmt)
	{
		if (!(fmt = ft_strchr((char *)fmt, '%')))
			break ;
		sub = make_tsub((char **)&fmt, ap, 0);
		s = clean(s, sub, (char **)&fmt, &slen);
	}
	va_end(ap);
	write(fd, s, slen);
	ft_strdel(&s);
	return (slen);
}
