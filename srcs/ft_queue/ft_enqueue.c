/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:36:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:50:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_mem.h"

void	ft_enqueue(t_queue *queue, void *content)
{
	t_qnode		*node;

	if (!queue)
		return ;
	node = (t_qnode *)ft_memalloc(sizeof(t_qnode));
	if (!node)
		return ;
	node->content = content;
	node->next = 0;
	if (!(queue->first))
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
}
