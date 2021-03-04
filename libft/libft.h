/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 11:43:38 by dmilan            #+#    #+#             */
/*   Updated: 2021/03/04 12:36:33 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# include <stddef.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*
**  ft_mem
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_calloc_c(size_t count, size_t size, int c);

/*
**  ft_str
*/
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_strfill(char fill, int n);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
const char			*ft_strskip_char(const char *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strnew(int n);
char				*ft_strjoinfree(char *s1, const char *s2);
int					ft_strcount(const char *s, char c);
const char			*ft_strskip(const char *s, int (*is_that)(int));

/*
**  ft_chr
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(char c);
int					ft_isblank(char c);

/*
**  ft_put
*/
void				ft_putc_fd(char c, int fd);
void				ft_putuc_fd(unsigned char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstrn_fd(char *s, int n, int fd);
void				ft_putendl();
void				ft_puti(int n);
void				ft_puti_endl(int n);
void				ft_puti_fd(int n, int fd);
void				ft_putcpp_fd(char **arr, int fd);
void				ft_putcppn_fd(char **arr, int n, int fd);

/*
**  ft_int
*/
int					ft_leni(int n);
int					ft_abs(int a);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
void				ft_swapi(int *a, int *b);

/*
**  ft_lst
*/
typedef struct		s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst);
void				ft_lstiter(t_list *lst, void (*f)(int));
void				ft_lst_put(t_list *list, void(*put)(int content));
void				ft_lst_swap(t_list **head, t_list *a, t_list *b);
void				ft_lst_bubble_sort(t_list **list,
										int(*compare)(t_list *, t_list *));


/*
**  ft_point
*/
typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

t_point				ft_point_add(t_point a, t_point b);
t_point				ft_point_new(double x, double y);
double				ft_point_len(t_point point);
t_point				ft_point_rotate(t_point point, double angle);

/*
**  ft_color
*/
typedef struct		s_color
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				argb;
}					t_color;

int					ft_color_argb(unsigned char a, unsigned char r,
									unsigned char g, unsigned char b);
t_color				ft_color_new(unsigned char a, unsigned char r,
									unsigned char g, unsigned char b);
/*
**  ft_other
*/
int					get_next_line(int fd, char **line);
int					ft_lenui(unsigned int n);
int					ft_lenui_hex(unsigned int n);
int					ft_lenul_hex(unsigned long n);
char				**ft_split(char const *s, char c);
char				*ft_uitoa(unsigned int n);

#endif
