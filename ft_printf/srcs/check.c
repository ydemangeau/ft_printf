/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:12:59 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 10:39:44 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		check_flags(const char **format, t_flag *flags)
{
	flags->sign = 0;
	flags->justify = 0;
	flags->prefix = 0;
	flags->zero = 0;
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
			flags->zero = 1;
		else if (**format == ' ')
			flags->space = 1;
		(*format)++;
	}
}

void		check_width(const char **format, va_list *args, t_handler *handler)
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
}

void		check_precision(const char **format, va_list *args,
		t_handler *handler)
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
}

int			check_lenght(const char **format, t_handler *handler)
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
	else if (**format == 'z')
		handler->lenght = z;
	else if (**format == 'j')
		handler->lenght = j;
	else if (**format == 'L')
		handler->lenght = L;
	else
		return (-1);
	(*format)++;
	return (1);
}
