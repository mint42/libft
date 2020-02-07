/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:52:16 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:48:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"

void	ft_treeiter(struct s_binarytree *binarytree,
			void (*f)(struct s_binarytree *))
{
	if (!binarytree || !f)
		return ;
	if (binarytree->left)
		ft_treeiter(binarytree->left, f);
	f(binarytree);
	if (binarytree->right)
		ft_treeiter(binarytree->right, f);
}
