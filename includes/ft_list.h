/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:03:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:07:51 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content);
t_list				*ft_lstinit(void *content);

void				ft_lstadd(t_list **head, t_list *link);
void				ft_lstadd_tail(t_list **head, t_list *link);

void				ft_lstdel(t_list **list, void (*del)());
void				ft_lstdelcontent(void *content);
void				ft_lstdelone(t_list **link, void (*del)());

void				ft_lstiter(t_list *list, void (*f)(t_list *link));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *link));

#endif
