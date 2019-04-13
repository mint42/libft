/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 22:58:17 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define BUF(lst) (((t_file *)(lst->content))->buf)

typedef struct	s_file
{
	char		*buf;
	int			fide;
}				t_file;

int				get_next_line(const int fd, char **line);
int				get_next_char(const int fd, char c, char **line);

#endif
