/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:46:55 by kkalinic          #+#    #+#             */
/*   Updated: 2020/12/04 16:00:16 by kkalinic         ###   ########.fr       */
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

static int			ft_skip(char *str, t_list *list, char **line, int r)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (i < ft_strlen(list->content))
	{
		*line = ft_substr(list->content, 0, i);
		tmp = ft_substr(list->content, i + 1, ft_strlen(list->content));
		free(list->content);
		list->content = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = list->content;
		list->content = ft_strdup("");
		return (0);
	}
	return (1);
}

static int			ft_gnl_cond(char *content, t_list *list, char **line, int i)
{
	if (i <= 0 && !content)
	{
		if (i == 0)
			*line = ft_strdup("");
		return (i);
	}
	return (ft_skip(content, list, line, i));
}

int					get_next_line(int fd, char **line)
{
	static t_list	list[FOPEN_MAX];
	char			*buff;
	int				i;
	char			*tmp;

	if ((BUFFER_SIZE + 1) <= 1 || !line ||
			(!(buff = malloc(sizeof(char) * BUFFER_SIZE +1))))
		return (-1);
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (list[fd].content != NULL)
		{
			tmp = ft_strjoin(list[fd].content, buff);
			free(list[fd].content);
			list[fd].content = tmp;
			if (ft_strchr(tmp, '\n'))
				break ;
		}
		else
			if (NULL == (list[fd].content = ft_strdup(buff)))
				return (-1);
	}
	if (buff != NULL)
		free(buff);
	return (ft_gnl_cond(list[fd].content, &list[fd], line, i));
}

int main()
{
	char *line;
	int fd;
	int fd2;


	line = "HEllo";
	fd = open("text.txt", O_RDONLY);
	fd2 = 0;
	while (0 < (fd2 = get_next_line(fd, &line)))
	{
		printf("%s", line);
		printf("\n--------------\n");
		free(line);
	}
	printf("%i\n", fd2);
	close(fd);
}
