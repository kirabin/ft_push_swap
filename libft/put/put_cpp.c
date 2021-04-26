#include "libft.h"

void	put_cpp(char **cpp)
{
	int		i;

	i = 0;
	while (cpp && cpp[i])
		put_two_strings(cpp[i++], "\n");
}

void	put_cpp_fd(char **cpp, int fd)
{
	int		i;

	i = 0;
	while (cpp && cpp[i])
		put_two_strings_fd(cpp[i++], "\n", fd);
}

void	put_cpp_n(char **cpp, int n)
{
	int		i;

	i = 0;
	while (cpp && cpp[i] && i < n)
		put_two_strings(cpp[i++], "\n");
}

void	put_cpp_n_fd(char **cpp, int n, int fd)
{
	int		i;

	i = 0;
	while (cpp && cpp[i] && i < n)
		put_two_strings_fd(cpp[i++], "\n", fd);
}
