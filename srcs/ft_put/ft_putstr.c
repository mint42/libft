/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/06/19 22:33:53 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fd.h"
#include "ft_str.h"
#include <unistd.h>

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(STDOUT_FD, s, ft_strlen(s));
}
