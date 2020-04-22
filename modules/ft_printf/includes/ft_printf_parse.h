/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:31:32 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:46:43 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSE_H
# define FT_PRINTF_PARSE_H

# include <stdarg.h>

char		*parse(t_sub *sub, va_list ap);
char		*parse_bouxp(t_sub *sub, va_list ap);
char		*parse_di(t_sub *sub, va_list ap);
char		*parse_efg(t_sub *sub, va_list ap);
char		*parse_unicode(t_sub *sub, va_list ap);
char		*parse_csp(t_sub *sub, va_list ap);

#endif
