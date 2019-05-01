/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:25:10 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:02:52 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char		*get_pref(const char **format, t_handler *handler, uintmax_t arg)
{
	char *pref;

	if (handler->flags.prefix && arg != 0)
	{
		if (**format == 'x')
			pref = "0x";
		if (**format == 'X')
			pref = "0X";
	}
	else
		pref = "";
	return (pref);
}

int			handle_hexa(const char **format, va_list *args, t_handler *handler)
{
	uintmax_t	arg;
	char		*pref;
	char		*str;
	int			i;

	i = -1;
	arg = cast_unsigned_lenght(args, handler);
	if (handler->precision >= 0 || handler->flags.justify)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width - 2;
	pref = get_pref(format, handler, arg);
	str = get_nbr(handler, arg, pref, 16);
	if (**format == 'x')
	{
		while (str[++i])
		{
			if (ft_isalpha(str[i]))
				str[i] = ft_tolower(str[i]);
		}
	}
	return (print_nbr(handler, str, -1));
}
