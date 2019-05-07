/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:17:51 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 13:17:31 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			check_convert(const char **format, va_list *args,
		t_handler *handler, int *len)
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
		*len += handle_percent(handler);
	else
		return (1);
	(*format)++;
	return (1);
}

int			handler(const char *format, va_list *args, int *len)
{
	t_handler	handler;
	const char	*tmp;

	tmp = format;
	if (*format == '\0')
		return (0);
	check_flags(&format, &handler.flags);
	check_width(&format, args, &handler);
	check_precision(&format, args, &handler);
	if (!(check_lenght(&format, &handler)))
		return (-1);
	check_convert(&format, args, &handler, len);
	return (format - tmp);
}

int			parser(const char *format, va_list *args, int len, int len_spec)
{
	char	*next_arg;

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
			ft_putnstr(format, (next_arg - format));
			len += (next_arg - format);
			format += (next_arg - format);
		}
		else
		{
			len_spec = handler(++format, args, &len);
			if (len_spec == -1)
				return (len);
			format += len_spec;
		}
	}
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;

	va_start(args, format);
	len = parser(format, &args, 0, 0);
	va_end(args);
	return (len);
}
