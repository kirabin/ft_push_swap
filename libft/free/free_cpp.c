#include "libft.h"

void	free_cpp(char **cpp)
{
	char	**temp;

	temp = cpp;
	while (temp && *temp)
		free(*temp++);
	free(cpp);
}
