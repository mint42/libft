/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:29:54 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 12:14:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>
#include <stdint.h>

int		ft_realloc(void **mem, size_t old_size, size_t new_size)
{
	void	*new_mem;
	size_t	i;

	new_mem = (void *)ft_memalloc(sizeof(void) * new_size);
	if (!new_mem)
		return (1);
	i = 0;
	while (i < old_size)
	{
		((uint8_t *)new_mem)[i] = ((uint8_t *)(*mem))[i];
		++i;
	}
	ft_memdel(mem);
	*mem = new_mem;
	return (0);
}
