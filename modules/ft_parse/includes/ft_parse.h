/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:51:09 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/29 13:13:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include <stddef.h>
# include <sys/types.h>

ssize_t		ft_parse_number(char **s, size_t *len);
char		*ft_parse_word(char **s, size_t *len);
char		*ft_parse_space(char **s, size_t *len);
char		*ft_parse_white_space(char **s, size_t *len);

void		ft_parse_skip_word(char **s);
void		ft_parse_skip_space(char **s);
void		ft_parse_skip_white_space(char **s);
void		ft_parse_skip_to_next_word(char **s);

size_t		ft_parse_count_word(const char *s);

#endif
