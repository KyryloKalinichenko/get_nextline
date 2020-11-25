/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:10:34 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/25 11:43:44 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	int				i;
	const char		*b;

	b = (char*)src;
	i = 0;
	while (b[i] != '\0' && n)
	{
		dest[i] = b[i];
		n--;
		i++;
	}
	while (n)
	{
		dest[i] = '\0';
		i++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = -1;
	dup = malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (dup == NULL)
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*a;
	int		i;
	int		p;

	i = 0;
	a = (char*)src;
	p = ft_strlen(a) + 1;
	while (dest[i] != '\0')
		i++;
	while (--p)
	{
		dest[i] = *a;
		i++;
		a++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		i = 0;
		j = 0;
		while (s[i])
		{
			if (i >= start && j < len)
			{
				str[j] = s[i];
				j++;
			}
			i++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *a;

	if (s1 && s2)
	{
		a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (a == NULL)
			return (NULL);
		a[(ft_strlen(s1) + ft_strlen(s2))] = '\0';
		a = ft_strncpy(a, s1, (ft_strlen(s1) + 1));
		a = ft_strcat(a, s2);
		return (a);
	}
	return (NULL);
}

