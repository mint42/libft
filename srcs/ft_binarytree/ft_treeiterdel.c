/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiterdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:36:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"

void	ft_treeiterdel(t_binarytree **binarytree, void (*f)(), void (*del)())
{
	if (*binarytree)
	{
		if ((*binarytree)->left)
			ft_treeiterdel(&(*binarytree)->left, f, del);
		f(*binarytree);
		if ((*binarytree)->right)
			ft_treeiterdel(&(*binarytree)->right, f, del);
		ft_treedelone(binarytree, del);
	}
}
