/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_skip_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:07:06 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 13:08:44 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_parse_skip_word(char **s)
{
	if (!(*s))
		return ;
	while (!ft_isspace(**s))
		++(*s);
}
