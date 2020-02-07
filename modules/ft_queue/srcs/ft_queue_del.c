/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:39:17 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 18:59:47 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"
#include "ft_mem.h"

void	ft_queue_del(t_queue **queue, void (*del)(void *))
{
	void	*content;

	if (!(*queue))
		return ;
	content = 0;
	while (!ft_queue_is_empty(*queue))
	{
		content = ft_dequeue(*queue);
		del(content);
	}
	ft_memdel((void **)queue);
}
