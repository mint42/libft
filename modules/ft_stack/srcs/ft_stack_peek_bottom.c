/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_peek_bottom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:01:27 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:07:41 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_stack_peek_bottom(t_stack *stack)
{
	if (!stack || !(stack->bottom))
		return (0);
	return (stack->bottom->content);
}
