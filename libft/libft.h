#ifndef LIBFT_H
# define LIBFT_H
# define PI 3.14159265359
# define STD_IN 0
# define STD_OUT 1
# define STD_ERROR 2
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef unsigned int	t_color;

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

bool	is_path(char *string);
bool	is_absolute_path(char *string);
bool	is_relative_path(char *string);
char	*get_file_name_from_path(char *path);

int64_t	_atoi_long_long(const char *str);
int		_atoi(const char *str);
char	*_itoa(int n);
int		_strcmp(const char *s1, const char *s2);
int		_strncmp(const char *s1, const char *s2, size_t n);
char	*_strdup(const char *s1);
char	*_strndup(const char *s1, int n);
int		_strlen(const char *s);
char	*_strnstr(const char *haystack, const char *needle, size_t len);
char	*_strtrim(char *s1, char *set);
int		count_char(const char *s, char c);
char	*fill_string(char *s, char c);
char	*find_char(const char *s, int c);
char	*get_next_line(int fd);
char	*get_string_slice(char *s, int start, int stop);
char	*skip_char(char *s, char c);
char	*string_join(char const *s1, char const *s2);
char	*string_join_char(char *s, char c);
char	*string_join_three(char const *s1, char const *s2, char const *s3);
char	*string_join_free(char *s1, const char *s2);
char	*string_join_free_rev(const char *s1, char *s2);
char	*string_join_free_free(char *s1, char *s2);
char	**split_string(const char *s, char c);
bool	is_name(const char *str);

bool	is_alpha(char c);
bool	is_digit(char c);
bool	is_ascii(char c);
bool	is_space(char c);
char	to_upper(char c);
char	to_lower(char c);

void	put_char(char c);
void	put_char_fd(char c, int fd);
void	put_char_times(char c, int times);
void	put_cpp(char **cpp);
void	put_cpp_fd(char **cpp, int fd);
void	put_cpp_n(char **cpp, int n);
void	put_cpp_n_fd(char **cpp, int n, int fd);
void	put_int(int n);
void	put_int_fd(int n, int fd);
void	put_string(char *s);
void	put_string_fd(char *s, int fd);
void	put_string_n(char *s, int n);
void	put_string_n_fd(char *s, int n, int fd);
void	put_two_strings(char *s1, char *s2);
void	put_two_strings_fd(char *s1, char *s2, int fd);
void	put_uint(unsigned int n);
void	put_uint_fd(unsigned int n, int fd);
void	put_uint_hex(unsigned int n, int is_upper);
void	put_uint_hex_fd(unsigned int n, int is_upper, int fd);

int		_abs(int a);
int		int_len(int n);
int		int_min(int a, int b);
int		int_max(int a, int b);
void	swap_int(int *a, int *b);
bool	is_number(char *str);
bool	is_integer(char *str);
bool	is_long_long(char *str);

void	*_calloc(size_t count, size_t size);

void	clear_list(t_list **lst, void (*del)(void*));
void	delete_list(t_list *lst, void (*del)(void*));
t_list	*find_list(t_list *begin_list, void *data_ref,
			bool (*compare)(void *, void *));
void	list_add_back(t_list **lst, t_list *new);
void	list_add_front(t_list **lst, t_list *new);
t_list	*list_get_last(t_list *lst);
int		list_size(t_list *lst);
void	merge_lists(t_list **begin_list1, t_list *begin_list2);
t_list	*new_list(void *content);
t_list	*new_list_int(int a);
void	put_list(t_list *list, void (*put)(void *content));
void	reverse_list(t_list **begin_list);
void	sort_list(t_list **list, bool (*compare)(void *, void *));
bool	is_list_sorted(t_list *list, bool (*compare)(void *, void *));
bool	list_compare_int_more(void *a, void *b);
bool	list_compare_int_equal(void *a, void *b);
void	swap_list_content(t_list *a, t_list *b);

t_point	point_add(t_point a, t_point b);
t_point	point_new(double x, double y);
double	point_len(t_point point);
t_point	point_rotate(t_point point, double angle);

t_color	new_color(unsigned char a, unsigned char r, unsigned char g,
			unsigned char b);

void	free_cpp(char **cpp);

#endif
