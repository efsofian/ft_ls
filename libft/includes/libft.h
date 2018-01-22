/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seliasbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:26:25 by seliasbe          #+#    #+#             */
/*   Updated: 2018/01/07 13:20:41 by seliasbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# define BUFF_SIZE 4096
# define MAX_VALUE_FD 10000
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <stdbool.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
}	t_length;

typedef enum
{
	no,
	yes,
	o,
	x,
	X,
}	t_hash;

typedef struct	s_flags
{
	t_hash		hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flags;

typedef struct	s_params
{
	t_flags		flags;
	int			width;
	int			preci;
	t_length	length;
	char		specifier;
}				t_params;

int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_words(const char *s);
int				ft_sqrt(int nb);
int				ft_charinstr(const char *str, char c);
int				ft_abs(int nb);
int				ft_wctomb(char *s, wchar_t wchar);
int				ft_wcslen(const wchar_t *s);
int				ft_wclen(const wchar_t c);

void			ft_putchar(char c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_strclr(char *s);
void			ft_putstr(const char *s);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putendl(const char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(const char *s, int fd);
void			ft_strdel(char **as);
void			ft_striter(char *s, void(*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

char			*ft_strcat(char *dest, const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_itoa(int n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_strupcase(char *str);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_uitoa_base(uintmax_t val, int base, char c);

size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_wcstombs(char *s, const wchar_t *old_ws, size_t len);

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
int				get_next_line(int const fd, char **line);
int				ft_printf(const char *format, ...);
int				parse_params(int indx, const char *format, t_params *params,
				va_list ap);
int				parse_specifiers(va_list ap, t_params *params);
void			parse_numb_specifiers(t_params *params, char specifier,
				intmax_t numb);
int				flags(const char *format, t_params *params);
int				width(const char *format, t_params *params, va_list ap);
int				precision(const char *format, t_params *params, va_list ap);
int				length(const char *format, t_params *params);
int				number(va_list ap, t_params *params);
int				symbol(va_list ap, t_params *params);
int				string(va_list ap, t_params *params);
int				no_specifier(t_params *params);
void			push_left(t_params *params, char **line, int size, char *str);
void			push_right(t_params *params, char **line, int size, char *str);
int				get_size(char *str, t_params *params);
int				is_multibyte(char *str);
void			ft_lstrev(t_list **head);
size_t			ft_intlen(int n);
#endif
