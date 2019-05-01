/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:34:19 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:03:29 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			handle_octal(va_list *args, t_handler *handler)
{
	uintmax_t	arg;
	char		*pref;

	arg = cast_unsigned_lenght(args, handler);
	if (handler->precision >= 0)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width - 1;
	if (handler->flags.prefix)
		pref = "0";
	else
		pref = "";
	return (print_nbr(handler, get_nbr(handler, arg, pref, 8), -1));
}
