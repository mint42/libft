/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:28:09 by rreedy            #+#    #+#             */
/*   Updated: 2018/06/01 16:24:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	if ((*list)->next)
		ft_lstdel(&((*list)->next), del);
	ft_lstdelone(list, del);
}
