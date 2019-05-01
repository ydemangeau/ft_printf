/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:17:09 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/01 18:02:31 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char		*get_float(t_handler *handler, long double arg, char *pref)
{
	char	*nb;
	char	*pnb;
	char	*str;
	int		len;
	int		i;

	i = -1;
	nb = ft_itoa_float(arg, 10);
	pnb = nb;
	len = handler->precision + ft_strlen(pref) + 1;
	while (nb[++i] != '.')
		len++;
	str = ft_memalloc(sizeof(char) * len + 1);
	i = -1;
	while (++i < len)
	{
		if (*pref)
			str[i] = *pref++;
		else
			str[i] = *nb++;
	}
	ft_strdel(&pnb);
	return (str);
}

int			handle_float(va_list *args, t_handler *handler)
{
	double		arg;
	char		*pref;

	if (handler->lenght == l && handler->lenght == L)
		arg = va_arg(*args, long double);
	else
		arg = va_arg(*args, double);
	if (handler->precision == -1)
		handler->precision = 6;
	if (arg < 0 || handler->flags.sign || handler->flags.space)
	{
		if (arg < 0)
		{
			pref = "-";
			arg *= -1;
		}
		else if (handler->flags.sign)
			pref = "+";
		else
			pref = " ";
	}
	else
		pref = "";
	return (print_nbr(handler, get_float(handler, arg, pref), -1));
}
