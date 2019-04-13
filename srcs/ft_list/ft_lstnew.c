/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:49:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_list	*ft_lstnew(void const *content)
{
	t_list *link;

	link = (t_list *)ft_memalloc(sizeof(t_list));
	if (!link)
		return (0);
	link->next = 0;
	if (!content)
	{
		link->content = 0;
		return (link);
	}
	link->content = ft_memalloc(sizeof(content));
	if (!link->content)
	{
		ft_memdel((void **)&link);
		return (0);
	}
	ft_memcpy(link->content, content, sizeof(content));
	return (link);
}
