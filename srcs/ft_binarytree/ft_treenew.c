/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:51:42 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/16 01:49:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"
#include "ft_mem.h"
#include <stddef.h>

t_binarytree	*ft_treenew(void *content, size_t content_size)
{
	t_binarytree	*node;

	node = (t_binarytree *)ft_memalloc(sizeof(t_binarytree));
	if (!node)
		return (0);
	if (!content)
	{
		node->content = 0;
		node->content_size = 0;
		node->left = 0;
		node->right = 0;
		return (node);
	}
	node->content = ft_memalloc(content_size);
	if (!node->content)
	{
		ft_memdel((void **)&node);
		return (node);
	}
	ft_memcpy(node->content, content, content_size);
	node->content_size = content_size;
	node->left = 0;
	node->right = 0;
	return (node);
}
