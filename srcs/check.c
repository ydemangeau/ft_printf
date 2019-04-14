#include "../include/printf.h"
#include "../include/struct.h"

int		check_flags(const char **format, t_flag *flags)
{
	flags->sign = 0;
	flags->justify = 0;
	flags->prefix = 0;
	flags->pad_zero = 0;
	flags->space = 0;

	while (**format == '-' || **format == '+' || **format == ' '
				|| **format == '0' || **format == '#')
	{
		if (**format == '+')
			flags->sign = 1;
		else if (**format == '-')
			flags->justify = 1;
		else if (**format == '#')
			flags->prefix = 1;
		else if (**format == '0')
			flags->pad_zero = 1;
		else if (**format == ' ')
			flags->space = 1;
		(*format)++;
	}
	return (1);
}

int		check_width(const char **format, va_list *args, t_handler *handler)
{
	handler->field_width = 0;
	while (ft_isdigit(**format) || **format == '*')
	{
		if (**format == '*')
		{
			handler->field_width = va_arg(*args, int);
			(*format)++;
			break ;
		}
		handler->field_width *= 10;
		handler->field_width += (**format - '0');
		(*format)++;
	}
	//printf("width = %d\n", handler->field_width);
	return (1);
}

int		check_precision(const char **format, va_list *args, t_handler *handler)
{
	handler->precision = -1;
	if (**format == '.')
	{
		handler->precision = 0;
		(*format)++;
		while (ft_isdigit(**format) || **format == '*')
		{
			if (**format == '*')
			{
				handler->precision = va_arg(*args, int);
				(*format)++;
				break ;
			}
			handler->precision *= 10;
			handler->precision += (**format - '0');
			(*format)++;
		}
	}
	//printf("precision = %d\n", handler->precision);
	return (1);
}

int		check_lenght(const char **format, t_handler *handler)
{
	handler->lenght = none;
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		handler->lenght = hh;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		handler->lenght = ll;
		(*format)++;
	}
	else if (**format == 'h')
		handler->lenght = h;
	else if (**format == 'l')
		handler->lenght = l;
	else
		return (1);
	(*format)++;
	//printf("lenght = %d\n", handler->lenght);
	return (1);
}






