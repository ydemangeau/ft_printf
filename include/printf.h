#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/libft.h"
#include "struct.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>



int		handle_int(va_list *args, t_handler *handler);

int		ft_printf(const char *format, ...);
int		check_flags(const char **format, t_flag *flags);
int		check_width(const char **format, va_list *args, t_handler *handler);
int		check_lenght(const char **format, t_handler *handler);
int		check_precision(const char **format, va_list *args, t_handler *handler);




#endif
