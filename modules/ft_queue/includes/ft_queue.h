/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:45:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/07 04:15:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

typedef struct		s_qnode
{
	void			*content;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_queue
{
	struct s_qnode	*first;
	struct s_qnode	*last;
}					t_queue;

t_queue				*ft_queue_init(void);

void				ft_queue_del(t_queue **queue, void (*del)(void *));
void				ft_queue_del_content(void *content);

void				ft_enqueue(t_queue *queue, void *content);

void				*ft_dequeue(t_queue *queue);
void				*ft_queue_peek(t_queue *queue);
int					ft_queue_is_empty(t_queue *queue);

#endif
