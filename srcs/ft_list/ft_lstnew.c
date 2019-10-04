/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:49:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:16:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include <stddef.h>

struct s_list	*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list *node;

	node = (struct s_list *)ft_memalloc(sizeof(struct s_list));
	if (!node)
		return (0);
	node->next = 0;
	if (!content)
	{
		node->content = 0;
		node->content_size = 0;
		return (node);
	}
	node->content = ft_memalloc(content_size);
	if (!node->content)
	{
		ft_memdel((void **)&node);
		return (0);
	}
	ft_memcpy(node->content, content, content_size);
	node->content_size = content_size;
	return (node);
}
