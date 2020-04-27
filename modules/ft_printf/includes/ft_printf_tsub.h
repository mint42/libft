/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tsub.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:32:33 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 09:58:42 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TSUB_H
# define FT_PRINTF_TSUB_H

# include <stddef.h>
# include <stdarg.h>

typedef struct		s_sub
{
	char			*s;
	unsigned int	flags;
	unsigned int	type;
	unsigned int	base;
	int				p;
	int				w;
	int				j;
	size_t			len;
}					t_sub;

t_sub				make_tsub(char **fmt, va_list ap, int init);

#endif
