/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:57:35 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 12:09:06 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_percent(t_handler *handler)
{
	if (handler->precision >= 0 || handler->flags.justify)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width - 1;
	return (print_nbr(handler, ft_strdup("%"), -1));
}
