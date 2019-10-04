/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiterdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:36:19 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:48:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binarytree.h"

void	ft_treeiterdel(struct s_binarytree **binarytree,
			void (*f)(struct s_binarytree *), void (*del)(void *, size_t))
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
