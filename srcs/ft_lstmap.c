/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:45:52 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/02 15:59:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *link))
{
	t_list	*nlist;
	t_list	*cur;

	if (!list || !f)
		return (0);
	cur = f(list);
	nlist = cur;
	while (list->next)
	{
		list = list->next;
		cur->next = f(list);
		if (!cur->next)
		{
			while (nlist)
			{
				cur = nlist->next;
				free(nlist);
				nlist = cur;
			}
			return (0);
		}
		cur = cur->next;
	}
	return (nlist);
}
