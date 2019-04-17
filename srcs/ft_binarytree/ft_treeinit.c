/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:07:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 03:25:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"
#include "ft_mem.h"
#include <stdlib.h>

t_binarytree	*ft_treeinit(void *content, size_t content_size)
{
	t_binarytree	*node;

	node = (t_binarytree *)ft_memalloc(sizeof(t_binarytree));
	if (!node)
		return (0);
	node->content = content;
	node->content_size = content_size;
	node->left = 0;
	node->right = 0;
	return (node);
}
