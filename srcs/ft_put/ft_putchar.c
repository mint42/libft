/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:06:46 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 22:33:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(STDOUT_FD, &c, 1);
}
