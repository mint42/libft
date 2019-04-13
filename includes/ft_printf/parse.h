/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:31:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:33:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdarg.h>

char		*parse(t_sub *sub, va_list ap);
char		*parse_bouxp(t_sub *sub, va_list ap);
char		*parse_di(t_sub *sub, va_list ap);
char		*parse_efg(t_sub *sub, va_list ap);
char		*parse_unicode(t_sub *sub, va_list ap);
char		*parse_csp(t_sub *sub, va_list ap);

#endif

