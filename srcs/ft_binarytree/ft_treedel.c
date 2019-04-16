/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:53:35 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/16 01:47:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"

void	ft_treedel(t_binarytree **binarytree, void (*del)(void *, size_t))
{
	if (*binarytree)
	{
		if ((*binarytree)->left)
			ft_treedel(&(*binarytree)->left, del);
		if ((*binarytree)->right)
			ft_treedel(&(*binarytree)->right, del);
		ft_treedelone(binarytree, del);
	}
}
