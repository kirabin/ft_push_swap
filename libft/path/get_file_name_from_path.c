#include "libft.h"

char	*get_file_name_from_path(char *path)
{
	char	*file_name;

	file_name = path;
	while (*path)
	{
		if (*path++ == '/')
			file_name = path;
	}
	return (file_name);
}
