/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:36:47 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:04:18 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_string(va_list *args, t_handler *handler)
{
	char	*arg;
	char	*str;
	int		len;
	int		slen;

	handler->flags.zero = 0;
	arg = va_arg(*args, char*);
	if (arg == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	slen = ft_strlen(arg);
	if (handler->precision == 0)
		len = 0;
	else if (handler->precision > 0)
		len = handler->precision;
	else
		len = slen;
	str = ft_strsub(arg, 0, len);
	return (print_nbr(handler, str, -1));
}
