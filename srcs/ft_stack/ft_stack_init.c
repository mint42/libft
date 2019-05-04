/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:15:56 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:05:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_mem.h"

t_stack		*ft_stack_init(void)
{
	t_stack		*stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->top = 0;
	stack->bottom = 0;
	return (stack);
}
