/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 04:07:59 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:28:38 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"
#include "ft_mem.h"
#include <stdlib.h>

struct s_binarytree		*ft_treeinit(void *content, size_t content_size)
{
	struct s_binarytree		*node;

	node = (struct s_binarytree *)ft_memalloc(sizeof(struct s_binarytree));
	if (!node)
		return (0);
	node->content = content;
	node->content_size = content_size;
	node->left = 0;
	node->right = 0;
	return (node);
}
