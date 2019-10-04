/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:03:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:49:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

struct s_list		*ft_lstnew(const void *content, size_t content_size);
struct s_list		*ft_lstinit(void *content, size_t content_size);

void				ft_lstadd(struct s_list **head, struct s_list *node);
void				ft_lstadd_tail(struct s_list **head, struct s_list *node);

void				ft_lstdel(struct s_list **list,
						void (*del)(void *, size_t));
void				ft_lstdelone(struct s_list **node,
						void (*del)(void *, size_t));
void				ft_lstdelcontent(void *content, size_t content_size);

void				ft_lstiter(struct s_list *list, void (*f)(struct s_list *));
struct s_list		*ft_lstmap(struct s_list *list,
						struct s_list *(*f)(struct s_list *));

int					ft_lstlen(struct s_list *list);

#endif
