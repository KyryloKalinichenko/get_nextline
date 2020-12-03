#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define BUFF_SIZE 1000000
#include <stdlib.h>

typedef struct                  s_list
{
        void            *content;
        struct s_list   *next;
}                               t_list;

int     get_next_line(int fd, char **line);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strdup(const char *s);
char            *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
char            *ft_strncpy(char *dest, const char *src, size_t n);
char    *ft_strcat(char *dest, const char *src);

#endif
