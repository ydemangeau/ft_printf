#include "../include/printf.h"
#include "../include/struct.h"

int		check_convert(const char **format, va_list *args, t_handler *handler, int *len)
{
	if (**format == 'd' || **format == 'i')
		*len += handle_int(args, handler);
	else if (**format == 'u')
		*len += handle_uint(args, handler);
	else if (**format == 'o')
		*len += handle_octal(args, handler);
	else if (**format == 'x' || **format == 'X')
		*len += handle_hexa(format, args, handler);
	else if (**format == 's')
		*len += handle_string(args, handler);
	else if (**format == 'c')
		*len += handle_char(args, handler);
	else if (**format == 'p')
		*len += handle_ptr(args, handler);
	else if (**format == 'f')
		*len += handle_float(args, handler);
	else if (**format == '%')
	{
		ft_putchar('%');
		*len += 1;
	}
	(*format)++;
	return (1);
}

int		handler(const char *format, va_list *args, int *len)
{
	t_handler handler;
	const char *tmp;

	tmp = format;
	if (*format == '\0')
		return (-1);
	if (!(check_flags(&format, &handler.flags)))
		return (-1);
	if (!(check_width(&format, args, &handler)))
		return (-1);
	if (!(check_precision(&format, args, &handler)))
		return (-1);
	if (!(check_lenght(&format, &handler)))
		return (-1);
	if (!(check_convert(&format, args, &handler, len)))
		return (-1);
	return (format - tmp);
}

int		parser(const char *format, va_list *args, int len)
{
	char	*next_arg;
	int		len_spec;
	
	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (len);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (len + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, (next_arg - format));
		return (parser(next_arg, args, len + (next_arg - format)));
	}
	else
	{
		if ((len_spec = handler(++format, args, &len)) == -1)
			return (-1);
		return (parser(format + len_spec, args, len));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = parser(format, &args, 0);
	va_end(args);
	//printf("len = %d\n",len);
	return (len);
}



