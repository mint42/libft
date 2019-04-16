/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:52:16 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/16 01:47:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"

void	ft_treeiter(t_binarytree *binarytree, void (*f)(t_binarytree *))
{
	if (binarytree->left)
		ft_treeiter(binarytree->left, f);
	f(binarytree);
	if (binarytree->right)
		ft_treeiter(binarytree->right, f);
}
