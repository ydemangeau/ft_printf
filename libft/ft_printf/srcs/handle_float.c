#include "../include/printf.h"

char	*get_float(t_handler *handler, long double arg, char *pref)
{
	char	*nb;
	char	*pnb;
	char	*str;
	int		len;
	int		i;

	i = -1;
	nb = ft_itoa_float(arg, 10);
	pnb = nb;
	//printf("len = %zd\n",ft_strlen(pref));
	//printf("precision = %d\n",handler->precision);
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
	//printf("len = %d\n",len);
	//printf("%s\n",str);
	ft_strdel(&pnb);
	return (str);
}

int		handle_float(va_list *args, t_handler *handler)
{
	double		arg;
	char	*pref;
	char *str;
	
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
		else if (handler->flags.space)
			pref = " ";
	}
	else
		pref = "";
	str = get_float(handler, arg, pref);
	//printf("arg = %f\n",arg);
	return  (print_nbr(handler, str));
	//return (print_nbr(handler, get_nbr(handler, arg, pref, 10)));
}


