/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:47:46 by ivalimak          #+#    #+#             */
/*   Updated: 2023/11/20 19:39:59 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// is
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isspace(int c);
int		ft_isinteger(char *n);

// put
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int *flags);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putxnbr_fd(unsigned int n, int fd, int upper);

// to
char	*ft_itoa(int n);
char	*ft_uitox(unsigned int n);
char	*ft_uitoa(unsigned int n);
long	ft_atol(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);

// int
size_t	ft_intlen(int n);
size_t	ft_uintlen(unsigned int n);

// str
size_t	ft_strlen(const char *s);
size_t	ft_strclen(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strrev(char *s);
int		ft_contains(const char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// mem
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// lst
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// printf
int		ft_printf(const char *s, ...);
int		ft_printformat(const char **f, va_list args);
int		ft_putarg(const char **f, va_list args);
int		ft_putc(va_list args, int *flags, char format);
int		ft_putd(va_list args, int *flags);
int		ft_putu(va_list args, int *flags);
int		ft_puts(va_list args, int *flags);
int		ft_putx(va_list args, int *flags, char format);
int		ft_putp(va_list args, int *flags);
int		ft_hexlen(unsigned long n);
int		putpadding(int spaces, char c, int *sign, int *flags);

// gnl
char	*get_next_line(int fd);
char	*bufshift(char *buf, char *src, size_t n);
char	*bufcopy(char *buf, char **out);

#endif
