#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>//lseek
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);

char    *get_next_line(int fd);

char    *read_file(int fd, char *save);
char    *get_line(char *save);
char    *save_line(char *save);
#endif