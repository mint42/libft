/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:37:00 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/20 12:55:45 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct		s_snode
{
	void			*content;
	struct s_snode	*next;
}					t_snode;

typedef struct		s_stack
{
	struct s_snode	*top;
}					t_stack;

t_stack				*ft_stack_init(void);
void				ft_stack_del(t_stack **stack, void (*del)(void *));
void				ft_stack_push(t_stack *stack, void *content);
void				*ft_stack_pop(t_stack *stack);
void				*ft_stack_peek(t_stack *stack);
int					ft_stack_is_empty(t_stack *stack);

#endif
