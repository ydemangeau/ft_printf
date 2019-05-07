/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:34:19 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 13:15:27 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			handle_octal(va_list *args, t_handler *handler)
{
	uintmax_t	arg;
	char		*pref;

	arg = cast_unsigned_lenght(args, handler);
	if (handler->flags.prefix && handler->precision == 0)
		handler->precision += 1;
	if (handler->precision >= 0)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width - 1;
	if (handler->flags.prefix && arg != 0)
	{
		pref = "0";
		handler->precision -= 1;
	}
	else
		pref = "";
	return (print_nbr(handler, get_nbr(handler, arg, pref, 8), -1));
}
