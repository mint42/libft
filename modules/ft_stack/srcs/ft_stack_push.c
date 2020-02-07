/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:16:57 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 00:45:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_mem.h"

void		ft_stack_push(t_stack *stack, void *content)
{
	t_snode		*node;

	if (!stack)
		return ;
	node = (t_snode *)ft_memalloc(sizeof(t_snode));
	if (!node)
		return ;
	node->content = content;
	node->next = 0;
	if (!(stack->top))
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
}
