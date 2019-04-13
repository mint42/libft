/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:38:39 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/07 17:00:11 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <stddef.h>

/*
**	Allocates a new string
*/

char		*ft_strinit(int c, size_t len);
char		*ft_strnew(size_t len);

/*
**	Frees a string and sets memory to zero
*/

void		ft_strdel(char **as);

/*
**	Gets the length of a string
*/

size_t		ft_strlen(const char *s);
size_t		ft_strlend(const char *s, int c);

/*
**	Searches a string and returns a pointer to a location on the string
*/

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchrs(const char *s, const char *cs);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
**	Compares two strings
*/

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t len);

/*
**	Duplicates a string
*/

char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t len);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);

/*
**	Concatenates string src onto the end of string dst
*/

char		*ft_strcata(char **dst, const char *src);
char		*ft_strncata(char **dst, const char *src, size_t len);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strncat(char *dst, const char *src, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstlen);

/*
**	Joins two strings together into a newly allocated string
*/

char		*ft_strjoin(const char *s1, const char *s2);

/*
**	Edits a string in some way
*/

void		ft_strclr(char *s);
char		*ft_strlower(char *s);
char		*ft_strupper(char *s);
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_stresize(char **s, int start, size_t len);
char		*ft_strpad(char **s, int start, size_t len, char c);

/*
**	Returns a substring of string s
*/

char		*ft_strtrim(const char *s);
char		*ft_strsub(const char *s, unsigned int start, size_t len);

/*
**	Calls a function on every character of the string
*/

void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**	Splits a string by whitespace into a double array of strings
*/

char		**ft_strsplit(const char *s, char c);

#endif
