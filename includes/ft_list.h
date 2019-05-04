/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:03:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/03 23:13:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstinit(void *content, size_t content_size);

void				ft_lstadd(t_list **head, t_list *node);
void				ft_lstadd_tail(t_list **head, t_list *node);

void				ft_lstdel(t_list **list, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **node, void (*del)(void *, size_t));
void				ft_lstdelcontent(void *content, size_t content_size);

void				ft_lstiter(t_list *list, void (*f)(t_list *));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *));

int					ft_lstlen(t_list *list);

#endif
