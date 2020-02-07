/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:35:47 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:16:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_tail(struct s_list **head, struct s_list *node)
{
	struct s_list	**cur;

	cur = head;
	if (!*cur)
		*cur = node;
	else
	{
		while ((*cur)->next)
			cur = &(*cur)->next;
		(*cur)->next = node;
	}
}
