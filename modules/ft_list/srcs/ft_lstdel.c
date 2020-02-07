/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:28:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:16:03 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_lstdel(struct s_list **list, void (*del)(void *, size_t))
{
	if (*list)
	{
		if ((*list)->next)
			ft_lstdel(&((*list)->next), del);
		ft_lstdelone(list, del);
	}
}
