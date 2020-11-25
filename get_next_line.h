/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:21:26 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/25 11:47:31 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char		*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_strdel(char **as);
char	*ft_strcat(char *dest, const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int	get_next_line(int fd, char **line);

#endif
