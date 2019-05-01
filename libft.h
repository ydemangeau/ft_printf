/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:27:30 by ydemange          #+#    #+#             */
/*   Updated: 2019/04/30 16:30:01 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 441

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, unsigned int size);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_putnstr(const char *s, int n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strncat(char *dest, const char *src, int nb);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_isblank(int c);
int					ft_sqrt(int nb);
int					ft_power(int nb, int power);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
int					ft_get_next_line(const int fd, char **line);
int					ft_abs(int i);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_unsigned(unsigned long long int value, int base);
char				*ft_itoa(int n);
char				*ft_itoa_float(long double nb, int base);
int					ft_printf(const char *format, ...);

#endif