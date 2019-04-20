/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:16:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:42:42 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_mem.h"

void		*ft_stack_pop(t_stack *stack)
{
	t_snode		*temp;
	void		*content;

	if (!stack || !(stack->top))
		return (0);
	temp = stack->top;
	content = stack->top->content;
	stack->top = stack->top->next;
	ft_memdel((void **)&temp);
	return (content);
}
