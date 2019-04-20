/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:35:47 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 21:41:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_tail(t_list **head, t_list *node)
{
	t_list	**cur;

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
