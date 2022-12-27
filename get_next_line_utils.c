/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:23:11 by ihashimo          #+#    #+#             */
/*   Updated: 2022/12/16 12:32:34 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	len;
	char	*ret;

	if (s1 == NULL && s2)
		s1 = "";
	else if (s1 && s2 == NULL)
		s2 = "";
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		ret[len++] = s1[i++];
	j = 0;
	while (s2[j] != '\0')
		ret[len++] = s2[j++];
	ret[len] = '\0';
	return (ret);
}
