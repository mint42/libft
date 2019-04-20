/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:49:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 21:41:00 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include <stddef.h>

void	ft_lstdelone(t_list **node, void (*del)(void *, size_t))
{
	del((*node)->content, (*node)->content_size);
	ft_memdel((void **)node);
}
