/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 20:45:09 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 21:14:52 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_crop(char **s, int in, size_t len)
{
	char	*str;

	str = ft_strnew(len);
	if (!str)
		return (0);
	ft_strncpy(str, *s + in, len);
	ft_strdel(s);
	return (str);
}
