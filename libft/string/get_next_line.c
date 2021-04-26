#include "libft.h"

static	char	*read_extra(char **extra, char **line)
{
	char	*endl;
	char	*temp;

	endl = NULL;
	if (*extra)
	{
		endl = find_char(*extra, '\n');
		if (endl)
		{
			*endl = '\0';
			*line = _strdup(*extra);
			temp = *extra;
			*extra = _strdup(++endl);
			free(temp);
		}
		else
		{
			*line = *extra;
			*extra = NULL;
		}
	}
	else
		*line = _strdup("");
	return (endl);
}

static void	fill_extra(char *endl, char **extra, int fd)
{
	*endl = '\0';
	extra[fd] = _strdup(++endl);
}

static int	free_and_get_minus_1(void *ptr)
{
	free(ptr);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char		*extra[1024];
	char			*endl;
	char			*buff;
	int				bytes_were_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || !buff)
		return (free_and_get_minus_1(buff));
	endl = read_extra(extra + fd, line);
	bytes_were_read = -1;
	while (!endl)
	{
		bytes_were_read = read(fd, buff, BUFFER_SIZE);
		if (!bytes_were_read)
			break ;
		if (bytes_were_read == -1)
			return (free_and_get_minus_1(buff));
		buff[bytes_were_read] = '\0';
		endl = find_char(buff, '\n');
		if (endl)
			fill_extra(endl, extra, fd);
		*line = string_join_free(*line, buff);
	}
	free(buff);
	return (bytes_were_read || _strlen(*line));
}
