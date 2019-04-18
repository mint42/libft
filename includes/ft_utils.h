/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:06:21 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 17:46:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int					ft_word_count(const char *s, int c);
unsigned int		ft_count_c(char *s, char c);

int					ft_tolower(int c);
int					ft_toupper(int c);

char				*ft_next_word(char *s);
char				*ft_skipspace(char *s);
char				*ft_skiptospace(char *s);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);

size_t				ft_numlen(long long int n);
size_t				ft_numlen_sign(long long int n);
size_t				ft_unumlen(unsigned long long int n);

#endif
