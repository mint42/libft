/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_skip_white_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:13:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 10:14:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include <stddef.h>

void	ft_parse_skip_white_space(char **s)
{
	if (!(*s))
		return ;
	while (ft_isspace(**s))
		++(*s);
}
