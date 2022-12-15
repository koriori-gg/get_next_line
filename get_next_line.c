#include "get_next_line.h"
//#define BUFFER_SIZE 42
/*
char	*ft_free(char *save, char *buf)
{
	char	*temp;

	temp = ft_strjoin(save, buf);
	free(save);
	return (temp);
}
*/

char	*ft_free(char *save, char *temp)
{
	char	*res;

	res = ft_strjoin(save, temp);
	free(save);
	return (res);
}

char	*read_file(int fd, char *save)
{
	char	*temp;
	int		bytes;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));//ma
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)//条件違う??<-leak reason
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}//x byte == 0 free()
		temp[bytes] = '\0';
		save = ft_free(save, temp);
	}
	free(temp);
	return (save);
}

char	*get_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (!save[i])//save->save[i]ok
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')//終端文字に関するルールは微妙
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	// line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);//x free(save)
	j = 0;
	while (j < i)
	{
		line[j] = save[j];
		j++;
	}
	//if (save[i] != '\0' && save[i] == '\n')//x if nothing
	//	line[i++] = '\n';
	//line[i] = '\0';callocしてるしいらんかも
	return (line);
}

char	*save_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rest = (char *)ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	if (!rest)//\0の時どうなってるか確認する必要あり
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		rest[j++] = save[i++];
	//rest[j] = '\0';callocやからいらんかも
	free(save);//free->null ume
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)//read(fd, 0, 0) < 0
		return (NULL);
	save = read_file(fd, save);
	if (!save)
		return (NULL);//x free
	line = get_line(save);
	save = save_line(save);
	return (line);
}