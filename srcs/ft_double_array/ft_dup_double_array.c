/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_double_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 23:52:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	**ft_dup_double_array(char **double_array)
{
	char	**cpy;
	int		i;

	i = 0;
	while (double_array && double_array[i])
		++i;
	cpy = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (double_array && *double_array)
	{
		cpy[i] = ft_strdup(*double_array);
		++double_array;
		++i;
	}
	return (cpy);
}
