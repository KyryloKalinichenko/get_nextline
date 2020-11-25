/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:59:02 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/25 13:36:19 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_lastcheck(char *s, char **line)
{
    int c;

    c = 0;
    while (s[c] != '\n' && s[c] != '\0')
        c++;
	if (s[c] == '\n')
	{
		*line = ft_substr(s, 0, c);
		ft_strdel(&s);
		if (s[0] == '\0')
			ft_strdel(s);
	}
	if (s[c] == '\0')
	{
		*line = ft_strdup(s);
		ft_strdel(&s);
	}
//	printf("%i\n", c); 
    return (1);
    
}

int	get_next_line(int fd, char **line)
{
	static char *s;
	char		buf[BUFF_SIZE + 1];
    int         i;
    char        *tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
        if (s == NULL)
            s = ft_strdup(buf);
        else
        {
            tmp = ft_strjoin(s, buf);
           	free(s);
           	s = tmp;
        }
        if (ft_strchr(s, '\n'))
            break;
    }
	if (i < 0)
		return (-1);
	if (i == 0 && s == NULL)
		return (0);
    return (ft_lastcheck(s, line));
}
/*
int main(void)
{
	char *line;

	printf("%i\n", get_next_line(1, &line)); 
	printf("%s\n", line); 
}*/
