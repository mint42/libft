/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:00:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:16:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(struct s_list *list, void (*f)(struct s_list *))
{
	if (!list || !f)
		return ;
	while (list)
	{
		f(list);
		list = list->next;
	}
}
