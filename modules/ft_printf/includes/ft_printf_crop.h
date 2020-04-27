/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_crop.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:33:49 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/27 10:00:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CROP_H
# define FT_PRINTF_CROP_H

# include <stddef.h>

typedef struct s_sub	t_sub;

char				*crop_di(t_sub *sub);
char				*crop_bouxp(t_sub *sub);
char				*crop_efg(t_sub *sub);
char				*crop_csp(t_sub *sub);
char				*crop_unicode(t_sub *sub);

#endif
