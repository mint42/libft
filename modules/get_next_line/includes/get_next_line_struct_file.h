/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_struct_file.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:22:23 by rreedy            #+#    #+#             */
/*   Updated: 2020/04/22 15:41:27 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_STRUCT_FILE_H
# define GET_NEXT_LINE_STRUCT_FILE_H

# define BUF(lst) (((struct s_file *)((lst)->content))->buf)
# define FD(lst) (((struct s_file *)((lst)->content))->fd)

struct		s_file
{
	char	*buf;
	int		fd;
};

#endif
