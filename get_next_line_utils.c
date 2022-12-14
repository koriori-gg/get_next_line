#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char)c;
	if (!s && cc)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((char)s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (s1 == NULL && s2)
		s1 = "";
	else if (s1 && s2 == NULL)
		s2 = "";
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));//change to malloc
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	if (size > SIZE_MAX / n)
		return (NULL);
	ret = malloc(size * n);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * n);
	return (ret);
}