/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iseletsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:22:53 by iseletsk          #+#    #+#             */
/*   Updated: 2018/05/04 16:22:01 by iseletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFF_SIZE 100

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdarg.h>
# include <wchar.h>
# include <wctype.h>

typedef struct		s_data
{
	char			**box;
	int				fd;
	int				i;
	struct s_data	*right;
	struct s_data	*left;
}					t_data;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_str
{
	char			*str;
	wchar_t			*astr;
}					t_str;

typedef struct		s_par
{
	char			*flag;
	char			*cast;
	int				width;
	int				precesion;
	int				c;
}					t_par;

int					ft_printf(const char *str, ...);

char				*ft_itoa_base(intmax_t nbr, int bs);

char				*ft_itoa_base_u(uintmax_t nbr, int bs);

int					ftp_hendl(const char *str, int count, va_list *ap, int *n);

int					ftp_hendl_flag(char *str, va_list *ap, t_par *data);

int					ftp_check_main_flag(char **str, t_par *data);

int					ftp_check_width(char **str, va_list *ap, t_par *data);

int					ftp_check_cast(char **str, t_par *data);

t_str				ftp_give_str(char *str, va_list *ap, t_par *data);

char				*ftp_strj_str(t_par data, t_str box);

void				ftp_putstr_del(char *str, int *n, t_par data);

int					ft_count_c(const char *str, int c);

char				*ftp_strj_nbr(t_par data, char *str_n);

char				*ftp_ntoa(t_par *data, char *str, va_list *ap);

char				*ftp_hendl_dinbr(t_par data, va_list *ap, char c);

char				*ftp_hendl_uxonbr(t_par *data, va_list *ap, char conv);

void				ftp_clear_data(t_par *data);

size_t				ft_unislen(wchar_t *ustr);

wchar_t				*ft_unisdup(wchar_t *src);

wchar_t				*ft_unisnew(size_t len);

wchar_t				*ft_uniscpy(wchar_t *dest, wchar_t *src, int n);

int					ft_size_uni(int	nb);

wchar_t				*ftp_strj_uni(t_par data, t_str box);

wchar_t				*ft_unisjoin(wchar_t *u1, wchar_t *u2);

void				ftp_putunis_del(wchar_t *ustr, int *n, t_par data);

void				ft_unisset(wchar_t *dest, int c, size_t len);

int					ft_putunic(wchar_t unic);

void				ftp_check_valid(t_par *data, char c);

t_str				ftp_give_p(void *adr, t_par *data);

void				ft_replace_c(char *str, char c, char r);
void				ftp_hendl_xnbr(t_par *data, char **str, char conv);

int					ft_abs(int val);
int					get_next_line(const int fd, char **line);

int					ft_read_output(char **line);

char				*ft_strjoin_md(char *s1, const char *sep, char *s2);

void				*ft_memset(void *s, int c, size_t n);

void				*ft_bzero(void *s, size_t n);

void				*ft_memcpy(void	*str, const void *src, size_t n);

void				*ft_memccpy(void *str, const void *src, int c, size_t n);

void				*ft_memmove(void *str, const void *src, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

size_t				ft_strlen(char *str);

char				*ft_strdup(const char *str);

char				*ft_strcat(char *restrict dest, const char *restrict src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *str, const char *needle);

char				*ft_strnstr(const char *big, const char *lit, size_t n);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_putchar(char c);

void				ft_putstr(char *s);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_skip_whtsp(char *str);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

int					ft_count_word(const char *s, char c);

int					ft_coundig(int nb);

char				*ft_itoa(int nb);

char				*ft_revers(char *s);

void				ft_putendl(char *str);

void				ft_putnbr(int nb);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alist, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstdup(t_list *lst);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
