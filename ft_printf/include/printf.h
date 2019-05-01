#ifndef PRINTF_H
# define PRINTF_H

#include "../../libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct	s_flag
{
	int			sign;//+
	int			justify;//-
	int			prefix;//#
	int			zero;//0
	int			space;// ' '
}				t_flag;

typedef enum	s_lenght
{
	none,
	h,
	hh,
	l,
	ll,
	j,
	z,
	L
}				t_lenght;

typedef struct	s_handler
{
	int			field_width;
	int			precision;
	t_lenght	lenght;
	t_flag		flags;
}				t_handler;

int		handle_percent(t_handler *handler);
int		handle_float(va_list *args, t_handler *handler);
int		handle_ptr(va_list *args, t_handler *handler);
int		handle_char(va_list *args, t_handler *handler);
int		handle_string(va_list *args, t_handler *handler);
int			handle_hexa(const char **format, va_list *args, t_handler *handler);
int			handle_octal(va_list *args, t_handler *handler);
int		print_nbr(t_handler *handler, char *nbr, int i);
char			*get_nbr(t_handler *handler, uintmax_t arg, char *pref, int base);

int		handle_uint(va_list *args, t_handler *handler);
int		handle_int(va_list *args, t_handler *handler);

int		ft_printf(const char *format, ...);
void check_flags(const char **format, t_flag *flags);
void		check_width(const char **format, va_list *args, t_handler *handler);
int		check_lenght(const char **format, t_handler *handler);
void		check_precision(const char **format, va_list *args, t_handler *handler);

intmax_t	cast_lenght(va_list *args, t_handler *handler);
uintmax_t	cast_unsigned_lenght(va_list *args, t_handler *handler);



#endif
