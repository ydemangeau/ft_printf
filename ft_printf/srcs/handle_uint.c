/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:37:29 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:04:33 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_uint(va_list *args, t_handler *handler)
{
	uintmax_t	arg;

	handler->flags.sign = 0;
	handler->flags.space = 0;
	arg = cast_unsigned_lenght(args, handler);
	return (print_nbr(handler, get_nbr(handler, arg, "", 10), -1));
}
