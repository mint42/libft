/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:33:49 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 17:45:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CROP_H
# define CROP_H

# include "tsub.h"
# include <stddef.h>

char				*crop_di(t_sub *sub);
char				*crop_bouxp(t_sub *sub);
char				*crop_efg(t_sub *sub);
char				*crop_csp(t_sub *sub);
char				*crop_unicode(t_sub *sub);

#endif
