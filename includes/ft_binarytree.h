/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:08:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/15 02:28:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_H
# define FT_BINARYTREE_H

# include <stddef.h>

typedef struct			s_binarytree
{
	void				*content;
	size_t				content_size;
	struct s_binarytree	*left;
	struct s_binarytree	*right;
}						t_binarytree;

void					ft_treedel(t_binarytree **binarytree,
								void (*del)(void *, size_t));

void					ft_treedelone(t_binarytree **node,
								void (*del)(void *, size_t));

void					ft_treeiter(t_binarytree *binarytree,
								void (*f)(t_binarytree *));

void					ft_treeiterdel(t_binarytree **binarytree,
								void (*f)(t_binarytree *),
								void (*del)(void *, size_t));

t_binarytree			*ft_treenew(void *content, size_t content_size);

t_binarytree			*ft_treeinit(void *content, size_t content_size);

#endif
