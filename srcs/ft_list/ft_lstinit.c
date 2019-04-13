/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:10:41 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:16 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_list	*ft_lstinit(void *content)
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
	link->content = content;
	return (link);
}
