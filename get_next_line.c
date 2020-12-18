/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:46:55 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/11 14:13:13 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char				*ft_strcat(char *dest, const char *src)
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

char				*ft_strncpy(char *dest, const char *src, size_t n)
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

static int			ft_skip(size_t i, t_list *list, char **line, size_t len)
{
	if (i < len)
	{
		if (!(*line = ft_substr(list->content, 0, i)))
			return (-1);
		if (!(list->tmp = ft_substr(list->content, i + 1, len)))
		{
			free(*line);
			return (-1);
		}
		free(list->content);
		if (!(list->content = ft_strdup(list->tmp)))
		{
			free(*line);
			free(list->tmp);
			return (-1);
		}
		free(list->tmp);
	}
	else if (list->r == 0)
	{
		*line = list->content;
		list->content = NULL;
		return (0);
	}
	return (1);
}

static int			ft_gnl_cond(char *content, t_list *list, char **line)
{
	unsigned int	j;
	unsigned int	len;

	j = 0;
	len = ft_strlen(list->content);
	if (list->r <= 0 && !content)
	{
		if (list->r == 0)
		{
			if (!(*line = ft_strdup("")))
				return (-1);
		}
		return (list->r);
	}
	if (content)
	{
		while (content[j] != '\0' && content[j] != '\n')
			j++;
	}
	return (ft_skip(j, list, line, len));
}

int					get_next_line(int fd, char **line)
{
	static t_list	list[FOPEN_MAX];
	char			*buff;
	int				i;

	if ((BUFFER_SIZE + 1) <= 1 || !line ||
			!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (list[fd].content != NULL)
		{
			if (!(list[fd].tmp = ft_strjoin(list[fd].content, buff)))
				i = -1;
			free(list[fd].content);
			list[fd].content = list[fd].tmp;
		}
		else if (NULL == (list[fd].content = ft_strdup(buff)))
			i = -1;
		if (ft_strchr(buff, '\n') || i == -1)
			break ;
	}
	free(buff);
	list->r = i;
	return (i == -1 ? -1 : ft_gnl_cond(list[fd].content, &list[fd], line));
}
/*
**int main()
**{
**	char *line;
**	int fd;
**	int fd2;
**
**	line = "HEllo";
**	fd = open("42_with_nl", O_RDONLY);
**	fd2 = 0;
**	while (0 < (fd2 = get_next_line(fd, &line)))
**	{
**		printf("%s", line);
**		printf("\n--------------\n");
**		free(line);
**		printf("%i\n", fd2);
**	}
**	if (fd > 0)
**		free(line);
**	close(fd);
**}
*/
