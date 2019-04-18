/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:00:36 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 19:04:12 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_ARRAY_H
# define FT_DOUBLE_ARRAY_H

# include <stddef.h>

void		ft_delete_double_array(char ***double_array);
char		**ft_dup_double_array(char **double_array);
size_t		ft_len_double_array(char **double_array);
void		ft_print_double_array(char **double_array);

#endif
