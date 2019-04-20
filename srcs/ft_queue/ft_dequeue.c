/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:35:42 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:45:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_mem.h"

void	*ft_dequeue(t_queue *queue)
{
	t_qnode		*temp;
	void		*content;

	if (!queue || !(queue->first))
		return (0);
	temp = queue->first;
	content = queue->first->content;
	queue->first = queue->first->next;
	ft_memdel((void **)temp);
	return (content);
}
