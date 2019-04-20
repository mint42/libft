/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:49:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 21:41:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include <stddef.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
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
