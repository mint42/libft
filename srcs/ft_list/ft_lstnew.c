/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:49:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/15 02:21:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include <stddef.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	link = (t_list *)ft_memalloc(sizeof(t_list));
	if (!link)
		return (0);
	link->next = 0;
	if (!content)
	{
		link->content = 0;
		link->content_size = 0;
		return (link);
	}
	link->content = ft_memalloc(content_size);
	if (!link->content)
	{
		ft_memdel((void **)&link);
		return (0);
	}
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	return (link);
}
