/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:06:15 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 23:07:09 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <stdlib.h>

# define SIGFIGS_I (f.len_i + f.trail_zeros)
# define SIGFIGS_F (f.len_f + f.lead_zeros)

typedef	union		u_double
{
	double			d;
	long int		l;
}					t_double;

typedef	struct		s_fp
{
	long			integer;
	long			fraction;
	int				len_i;
	int				len_f;
	int				lead_zeros;
	int				trail_zeros;
}					t_fp;

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
