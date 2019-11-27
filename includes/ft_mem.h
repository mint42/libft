/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:07:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/11/27 11:33:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stddef.h>

void		ft_bzero(void *s, size_t len);
void		*ft_memalloc(size_t size);
void		*ft_memcat(void *d, const void *s, size_t dl, size_t sl);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memchr(const void *s, int c, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *ptr, int c, size_t len);
void		*ft_memsec(void *ptr, int c, size_t len);
int			ft_realloc(void **mem, size_t old_size, size_t new_size);

#endif
