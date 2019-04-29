#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/libft.h"
#include "struct.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int		handle_float(va_list *args, t_handler *handler);
int		handle_ptr(va_list *args, t_handler *handler);
int		handle_char(va_list *args, t_handler *handler);
int		handle_string(va_list *args, t_handler *handler);
int			handle_hexa(const char **format, va_list *args, t_handler *handler);
int			handle_octal(va_list *args, t_handler *handler);
int		print_nbr(t_handler *handler, char *nbr);
char			*get_nbr(t_handler *handler, uintmax_t arg, char *pref, int base);

int		handle_uint(va_list *args, t_handler *handler);
int		handle_int(va_list *args, t_handler *handler);

int		ft_printf(const char *format, ...);
int		check_flags(const char **format, t_flag *flags);
int		check_width(const char **format, va_list *args, t_handler *handler);
int		check_lenght(const char **format, t_handler *handler);
int		check_precision(const char **format, va_list *args, t_handler *handler);

intmax_t	cast_lenght(va_list *args, t_handler *handler);
uintmax_t	cast_unsigned_lenght(va_list *args, t_handler *handler);



#endif
