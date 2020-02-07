/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarytree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:08:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:08:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARYTREE_H
# define FT_BINARYTREE_H

# include <stddef.h>

struct						s_binarytree
{
	void					*content;
	size_t					content_size;
	struct s_binarytree		*left;
	struct s_binarytree		*right;
};

void						ft_treedel(struct s_binarytree **binarytree,
								void (*del)(void *, size_t));

void						ft_treedelone(struct s_binarytree **node,
								void (*del)(void *, size_t));

void						ft_treeiter(struct s_binarytree *binarytree,
								void (*f)(struct s_binarytree *));

void						ft_treeiterdel(struct s_binarytree **binarytree,
								void (*f)(struct s_binarytree *),
								void (*del)(void *, size_t));

struct s_binarytree			*ft_treenew(void *content, size_t content_size);

struct s_binarytree			*ft_treeinit(void *content, size_t content_size);

#endif
