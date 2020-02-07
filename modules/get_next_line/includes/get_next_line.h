/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/10/03 23:43:49 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define BUF(lst) (((struct s_file *)((lst)->content))->buf)
# define FD(lst) (((struct s_file *)((lst)->content))->fd)

struct		s_file
{
	char	*buf;
	int		fd;
};

int			get_next_line(const int fd, char **line);
int			get_next_char(const int fd, char c, char **line);

#endif
