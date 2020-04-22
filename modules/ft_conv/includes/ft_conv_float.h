/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_float.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:06:15 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:35:50 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_FLOAT_H
# define FT_CONV_FLOAT_H

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

#endif
