/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:28:35 by rreedy            #+#    #+#             */
/*   Updated: 2018/05/28 11:18:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;

	str = (char *)malloc(sizeof(char *) * ft_strlen(s) + 1);
	while (*s)
		*str++ = f(*s);
	*str = '\0';
	return (str);
}
