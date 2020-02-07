/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsub.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:32:33 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:33:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSUB_H
# define TSUB_H

# include <stddef.h>
# include <stdarg.h>

# define S sub->s
# define FLAGS sub->flags
# define TYPE sub->type
# define BASE sub->base
# define PREC sub->p
# define WIDTH sub->w
# define JUST sub->j
# define LEN sub->len

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
