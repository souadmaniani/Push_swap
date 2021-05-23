#include "get_next_line.h"
#define BUFFER_SIZE 1

char	*resize(char *line)
{
	int		i;
	char	*tmp;
	char	*ptr;

	i = 0;
	ptr = line;
	while (line[i] != '\n' && line[i])
		i++;
	tmp = ft_calloc(i + 1, 1);
	if (!tmp)
		return (0);
	line[i] = '\0';
	ft_strcpy(tmp, line);
	free(ptr);
	ptr = NULL;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (0);
	ft_strcpy(line, tmp);
	free(tmp);
	tmp = NULL;
	return (line);
}

int	free_table(char **table, char **ptr)
{
	free(*table);
	*table = NULL;
	free(*ptr);
	*ptr = NULL;
	return (-1);
}

int	fill_line(char **stock, char **line, int cas)
{
	char	*tmp;

	if (cas == 1)
	{
		if (*stock)
		{
			tmp = *line;
			*line = ft_strjoin(*stock, *line);
			if (!*line)
				return (-1);
			free_table(stock, &tmp);
		}
	}
	if (cas == 2)
	{
		tmp = *stock;
		*stock = ft_strjoin(*stock, *line);
		if (!*stock)
			return (-1);
		free_table(&tmp, line);
	}
	return (1);
}

int	search_new_line(char **line, char **tmp, int n, int fd)
{
	char	*ptr;

	*tmp = ft_strchr(*line, '\n');
	while (!*tmp)
	{
		ptr = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!ptr || n == -1)
			return (-1);
		n = read(fd, ptr, BUFFER_SIZE);
		if (n == 0)
		{
			free(ptr);
			return (0);
		}
		if (n == -1)
			return (free_table(line, &ptr));
		if (n && fill_line(line, &ptr, 2) == -1)
			n = -1;
		*tmp = ft_strchr(*line, '\n');
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	int			n;
	char		*tmp;
	int			res;

	*line = ft_calloc(1, 1);
	if (!BUFFER_SIZE || !*line)
		return (-1);
	if (fill_line(&stock, line, 1) == -1)
		n = -1;
	else
		n = 1;
	res = search_new_line(line, &tmp, n, fd);
	if (res == 0 || res == -1)
		return (res);
	stock = ft_calloc(ft_strlen(tmp + 1) + 1, 1);
	if (!stock)
		return (-1);
	ft_strcpy(stock, tmp + 1);
	*line = resize(*line);
	if (!*line)
		return (-1);
	return (1);
}
