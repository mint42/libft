/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:45:52 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/15 04:16:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *link))
{
	t_list	*newlist;
	t_list	*cur;

	if (!list || !f)
		return (0);
	cur = f(list);
	newlist = cur;
	while (list->next)
	{
		list = list->next;
		cur->next = f(list);
		if (!cur->next)
		{
			while (newlist)
			{
				cur = newlist->next;
				ft_memdel((void **)&newlist);
				newlist = cur;
			}
			return (0);
		}
		cur = cur->next;
	}
	return (newlist);
}
