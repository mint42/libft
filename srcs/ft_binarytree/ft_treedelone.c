/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:54:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:03:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"
#include "ft_mem.h"

void	ft_treedelone(struct s_binarytree **node, void (*del)(void *, size_t))
{
	if (*node)
	{
		del((*node)->content, (*node)->content_size);
		ft_memdel((void **)node);
	}
}
