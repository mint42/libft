/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:08:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 17:05:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_H
# define FT_BINARYTREE_H

typedef struct			s_binarytree
{
	void				*content;
	struct s_binarytree	*left;
	struct s_binarytree	*right;
}						t_binarytree;

void					ft_treedel(t_binarytree **binarytree, void (*del)());
void					ft_treedelone(t_binarytree **node, void (*del)());
void					ft_treeiter(t_binarytree *binarytree, void (*f)());
void					ft_treeiterdel(t_binarytree **binarytree, void (*f)(),
							void (*del)());
t_binarytree			*ft_treenew(void *content);

#endif
