/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 22:48:05 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:09:52 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_rrotate(t_stack *stack)
{
	t_snode		*cur;
	void		*content;

	if (!stack || !(stack->top) || !(stack->top->next) || !(stack->bottom))
		return ;
	cur = stack->top;
	while (cur->next->next)
		cur = cur->next;
	stack->bottom->next = stack->top->next;
	stack->top->next = stack->bottom;
	stack->bottom = cur;
	stack->bottom->next = cur;
	content = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = content;
}
