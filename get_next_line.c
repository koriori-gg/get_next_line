#include "get_next_line.h"
#define BUFFER_SIZE 42

char	*read_line(int fd, char *save)
{
	char	*temp;
	int		bytes;

	temp = (char *)ft_calloc(BUFFER_SIZE + 1,sizeof(char));//ma
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}//x byte == 0 free()
		temp[bytes] = '\0';
		save = ft_strjoin(save, temp);
	}
	free(temp);
	return (save);
}

char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')//終端文字に関するルールは微妙
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));//改行文字が1バイトか確認取る必要あり ma
	if (!line)
		return (NULL);//x free(save)
	i = 0;
	while (save[i] != '\0'&& save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] != '\0' && save[i] == '\n')//x if nothing
		line[i++] = '\n';
	line[i] = '\0';
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
	rest[j] = '\0';
	free(save);//free->null ume
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_line(fd, save);
	if (!save)
		return (NULL);//x free
	line = get_line(save);
	save = save_line(save);
	return (line);
}