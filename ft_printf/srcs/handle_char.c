/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:23:12 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 17:16:50 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_char(va_list *args, t_handler *handler)
{
	int arg;
	int len;

	arg = va_arg(*args, int);
	len = 1;
	while (len != handler->field_width &&
			handler->field_width && !handler->flags.justify)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putchar(arg);
	while (handler->flags.justify && len != handler->field_width
			&& handler->field_width)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}
