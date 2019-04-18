/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:06:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 17:44:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);

void		ft_putendl(const char *s);
void		ft_putendl_fd(const char *s, int fd);

void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);

void		ft_putstr(const char *s);
void		ft_putstr_fd(const char *s, int fd);

#endif
