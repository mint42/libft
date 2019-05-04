/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 22:58:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:00:35 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_swap(t_stack *stack)
{
	void	*content;
	if (!stack || !(stack->top) || !(stack->top->next) || !(stack->bottom))
		return ;
	content = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = content;
}
