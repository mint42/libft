/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:28:59 by rreedy            #+#    #+#             */
/*   Updated: 2018/09/03 21:29:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *s)
{
	char	*cur;

	cur = s;
	while (cur && *cur)
	{
		if (ft_islower(*cur))
			*cur = ft_toupper(*cur);
		++cur;
	}
	return (s);
}
