/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:06:15 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:32:11 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

int					ft_atoi(const char *str);
char				*ft_ctoa(int c);
char				*ft_ftoa(double n, int precision);
char				*ft_ftosn(double n, int precision);
char				*ft_itoa(int n);
char				*ft_itoabase(long long int n, int base);
char				*ft_uitoabase(unsigned long long int n, int base);

char				*conv_utf8_char(wchar_t wc, char *s);
char				*conv_utf8_str(wchar_t *ws, char *s);

#endif
