/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:36:47 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 13:12:37 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_string(va_list *args, t_handler *handler)
{
	char	*arg;
	char	*str;
	int		len;
	int		slen;

	arg = va_arg(*args, char*);
	if (arg == NULL)
	{
		if (handler->precision != 0)
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
		return (print_nbr(handler, str, -1));
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
