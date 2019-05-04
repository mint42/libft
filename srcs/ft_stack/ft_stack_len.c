/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:14:44 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:15:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		ft_stack_len(t_stack *stack)
{
	t_snode		*cur;
	int			len;

	if (!stack || !(stack->top))
		return (0);
	len = 0;
	cur = stack->top;
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	return (len);
}
