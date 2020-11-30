/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:46:55 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/30 15:58:52 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*skip(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (ft_substr(str, 0, i));
}

int	get_next_line(int fd, char **line)
{
	t_list *list[100];
	char buff[BUFF_SIZE + 1];
	int i;
	char *tmp;

	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (list[fd] == NULL)
		{
			list[fd] = ft_lstnew("\0");
			list[fd]->content = ft_strjoin(list[fd]->content, buff);
		}
		else 
		{
			tmp = ft_strjoin(list[fd]->content, buff);
			free(list[fd]->content);
		if (ft_strchr(tmp, '\n') &&
				!(ft_strcmp(skip(buff), list[fd]->content)))
				break;
		list[fd]->content = tmp;
		}

	}
	return (last_check(list[fd]));
}

int main()
{
	char *line;
	int fd;
	fd = open("text.txt", O_RDONLY);
//	fd = 0;
	while (0 < get_next_line(fd, &line))
	{
		printf("%s", line);
		printf("\n--------------\n");
	}
	close(fd);
	free(line);
}
