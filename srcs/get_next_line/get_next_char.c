/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:43:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/12 17:10:21 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_list.h"
#include <unistd.h>
#include <fcntl.h>

static int		fill_line(char **line, char **s, char c, int red)
{
	int		len;

	if (!*s)
		return (-1);
	if (!red && !ft_strlen(*s))
		return (0);
	len = ft_strchr(*s, c) ? ft_strchr(*s, c) - *s : ft_strlen(*s);
	*line = ft_strnew(len);
	if (!*line || red == -1)
	{
		if (*line)
			ft_strdel(line);
		return (-1);
	}
	*line = ft_strncpy(*line, *s, len);
	*s = ft_stresize(s, len + 1, BUFF_SIZE + (ft_strlen(*s) - len));
	return (*s ? 1 : -1);
}

static int		get_file(t_list **lst, int fd)
{
	t_file	*newf;

	if (!(*lst))
		return (-1);
	while ((*lst)->content && (((t_file *)((*lst)->content))->fide != fd))
	{
		if (!(*lst)->next)
			(*lst)->next = ft_lstnew(0);
		*lst = (*lst)->next;
	}
	if (!((*lst)->content))
	{
		if (!(newf = (t_file *)ft_memalloc(sizeof(t_file))))
			return (-1);
		if (!(newf->buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		newf->fide = fd;
		(*lst)->content = newf;
	}
	return (1);
}

int				get_next_char(const int fd, char c, char **line)
{
	static t_list	*head;
	t_list			*lst;
	int				red;

	red = BUFF_SIZE + 1;
	if (fd < 0 || !line)
		return (-1);
	if (!head)
		head = ft_lstnew(0);
	lst = head;
	if (get_file(&lst, fd) == -1)
		return (-1);
	while (BUF(lst))
	{
		if (ft_strchr(BUF(lst), c) || red < BUFF_SIZE)
			return (fill_line(line, &BUF(lst), c, red));
		red = read(fd, BUF(lst) + ft_strlen(BUF(lst)), BUFF_SIZE);
		if (red == BUFF_SIZE)
		{
			BUF(lst) = ft_stresize(&BUF(lst), 0,
					ft_strlen(BUF(lst)) + BUFF_SIZE);
		}
	}
	return (-1);
}
