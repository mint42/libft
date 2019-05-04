/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 22:40:25 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:08:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_rotate(t_stack *stack)
{
	t_snode		*rotatee;

	if (!stack || !(stack->top) || !(stack->top->next) || !(stack->bottom))
		return ;
	rotatee = stack->top;
	stack->top = stack->top->next;
	stack->bottom->next = rotatee;
	stack->bottom = stack->bottom->next;
	stack->bottom->next = 0;
}
