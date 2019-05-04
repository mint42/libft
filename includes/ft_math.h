/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:11:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/05/04 08:30:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

#include <stddef.h>

long long int		ft_abs(long long int n);
double				ft_absd(double n);
int					ft_ceiling(double n);
double				ft_dpow(int n, int exponent);
int					ft_floor(double n);
size_t				ft_pow(int n, int exponent);
long				ft_round(double n);

#endif
