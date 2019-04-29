#include "../include/printf.h"

int check_error(const char **format,va_list *args, t_handler *handler, int *len)
{
	const char *tmp;
	args = (void*)args;
//	void*			i;
//	i= va_arg(*args, void*);
//	if (i == 0x7ffccbccc2cfcc)
//	//	ft_putendl("OK");
	//printf("i = %p\n",i);
	tmp = *format +1;
	if (**format && (*tmp || handler->lenght != none) )
	{
		ft_putchar('%');
		*len += 1;
		if (handler->flags.prefix && (*len+=1))
			ft_putchar('#');
		if (handler->flags.space && (*len+=1))
			ft_putchar(' ');
		if (handler->flags.justify )
		{
			handler->flags.zero = 0;
			ft_putchar('-');
			*len += 1;
		}
		if (handler->flags.zero && (*len+=1))
			ft_putchar('0');
		if (handler->field_width)
		{
			ft_putnbr(handler->field_width);
			while (handler->field_width > 10)
			{
				handler->field_width /= 10;
				*len += 1;
			}
			*len += 1;
		}
		if (handler->precision >= 0)
		{	
			ft_putchar('.');
			ft_putnbr(handler->precision);
			while (handler->precision > 10)
			{
				handler->precision /= 10;
				*len += 1;
			}
			*len += 2;
		}
	}
	else
	{
		*len =-1;
		return (-1);
	}
	ft_putstr(*format);
	*len += ft_strlen(*format);
	return (-1);
}

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
	else
	{
		if (check_error(format,args, handler, len) == -1)
			return (-1);
		/*else
		{
			(*format)++;
			check_error(format, handler, len);
		}*/
		//(*format)++;

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
	{
		//ft_putchar('%');
		*len = -1;
		return (-1);
	}
	check_flags(&format, &handler.flags);
	check_width(&format, args, &handler);
	check_precision(&format, args, &handler);
	if (!(check_lenght(&format, &handler)))
		return (-1);
	if (check_convert(&format, args, &handler, len)== -1)
		return (-1);
	
	return (format - tmp);
}

int		parser_it(const char *format, va_list *args)
{
	
	char	*next_arg;
	int		len;
	int		len_spec;
	
	len_spec = 0;
	len = 0;
	while (*format)
	{
		next_arg = ft_strchr(format, '%');
		if (next_arg == NULL)
		{
			ft_putstr(format);
			return (len + ft_strlen(format));
		}
		if (next_arg > format)
		{
			//ft_putchar('B');
			ft_putnstr(format, (next_arg - format));
			//ft_putchar('C');
			len += (next_arg - format);
			format += (next_arg -format);
		}
		else
		{
			len_spec = handler(++format, args, &len);
			if (len_spec == -1)
				return (len);
			format += len_spec;
		}
	}
	return(len);
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
		len_spec = handler(++format, args, &len);
		if (len_spec == -1)
			return (-1);
		return (parser(format + len_spec, args, len));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = parser_it(format, &args);
	va_end(args);
	//printf("len = %d\n",len);
	return (len);
}



