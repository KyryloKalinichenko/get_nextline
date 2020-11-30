#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);

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

int	ft_lastcheck(char *s, int fd,  char **line)
{
	int i;
	char *tmp;

	while (*(s + i) != '\0' && *(s + i) != '\n')
		i++;
	if (*(s + i) == '\n')
	{
		*line = ft_substr(s, 0, i);
		tmp = ft_strdup(s + i);
		free(s);
		s = tmp;
		return (1);
	}
	else if (*(s + i) == '\0')
	{
		*line = ft_substr(s, 0, i);
		return (1);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char *s;
	char buff[BUFF_SIZE + 1];
	int	i;
	char	*tmp;
	
	if (fd >= 0)
	{
		while ((i = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[i] = '\0';
			if (s == NULL)
				s = ft_strdup("\0");
			if (s)
			{
				tmp = ft_strjoin(s, buff);
				free(s);
				s = tmp;
			}
			if (ft_strchr(s, '\n'))
				break;
		}
		if (i == 0)
			return (0);
		return (ft_lastcheck(s, fd,  line));
	
	}
	return (-1);
}

int main()
{
	char *line;
	int fd;

//	fd = open("text.txt", O_RDONLY);
	fd = 1;
	while (0 < get_next_line(fd, &line))
	{
		printf("%s", line);
		printf("\n--------------\n");
	}
	close(fd);
	free(line);
}
