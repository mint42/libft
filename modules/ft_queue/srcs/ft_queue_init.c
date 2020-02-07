/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:34:18 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:45:08 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_mem.h"

t_queue		*ft_queue_init(void)
{
	t_queue		*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->first = 0;
	queue->last = 0;
	return (queue);
}
