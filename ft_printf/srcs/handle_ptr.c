/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:35:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:45:57 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		handle_ptr(va_list *args, t_handler *handler)
{
	void		*arg;
	char		*pref;
	char		*str;
	int			i;

	//handler->precision = -1;
	i = -1;
	arg = va_arg(*args, void *);
	if (arg == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	pref = "0x";
	str = get_nbr(handler, (uintmax_t)arg, pref, 16);
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_tolower(str[i]);
	}
	return (print_nbr(handler, str, -1));
}
