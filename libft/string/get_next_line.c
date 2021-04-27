#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		ret;

	line = _strdup("");
	while (line && fd >= 0)
	{
		ret = read(fd, &buffer, 1);
		if (ret == -1)
		{
			free(line);
			return (NULL);
		}
		if (_strlen(line) == 0 && ret == 0)
		{
			free(line);
			return (NULL);
		}
		if (ret == 0 || buffer == '\n')
			return (line);
		line = string_join_char(line, buffer);
	}
	return (NULL);
}
