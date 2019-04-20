/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:13:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:53:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_mem.h"

void	ft_stack_del(t_stack **stack, void (*del)(void *))
{
	void	*content;

	content = 0;
	if (*stack)
	{
		while (!ft_stack_is_empty(*stack))
		{
			content = ft_stack_pop(*stack);
			del(content);
		}
		ft_memdel((void **)stack);
	}
}
