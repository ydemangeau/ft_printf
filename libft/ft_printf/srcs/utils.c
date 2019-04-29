#include "../include/printf.h"

intmax_t	cast_lenght(va_list *args, t_handler *handler)
{
	intmax_t		arg;

	arg = va_arg(*args, intmax_t);
	if (handler->lenght == h)
		arg = (short int)arg;
	else if (handler->lenght == hh)
		arg = (char)arg;
	else if (handler->lenght == l)
		arg = (long int)arg;
	else if (handler->lenght == ll)
		arg = (long long int)arg;
	else if (handler->lenght == j)
		arg = (intmax_t)arg;
	else if (handler->lenght == z)
		arg = (size_t)arg;
	else
		arg = (int)arg;
	return (arg);
}

uintmax_t	cast_unsigned_lenght(va_list *args, t_handler *handler)
{
	uintmax_t		arg;

	arg = va_arg(*args, uintmax_t);
	if (handler->lenght == h)
		arg = (unsigned short int)arg;
	else if (handler->lenght == hh)
		arg = (unsigned char)arg;
	else if (handler->lenght == l)
		arg = (unsigned long int)arg;
	else if (handler->lenght == ll)
		arg = (unsigned long long int)arg;
	else if (handler->lenght == j)
		arg = (uintmax_t)arg;
	else if (handler->lenght == z)
		arg = (size_t)arg;
	else
		arg = (unsigned int)arg;
	return (arg);
}

char			*get_nbr(t_handler *handler, uintmax_t arg, char *pref, int base)
{
	char *str;
	char *nb;
	char *pnb;
	int	nlen;
	int len;
	int i;
	
	i = -1;
	nb = ft_itoa_base_unsigned(arg, base);
	pnb = nb;
	nlen = ft_strlen(nb);
	if (arg == 0 && handler->precision == 0)
		len = 0;
	else if (handler->precision > 0)
		len = handler->precision > nlen ? handler->precision : nlen;
	else
		len = nlen;
	len += ft_strlen(pref);
	if(!(str = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i != len)
	{
		if (*pref)
			str[i] = *pref++;
		else if (i < (len - nlen))
			str[i] = '0';
		else
			str[i] = *nb++;
	}
	ft_strdel(&pnb);
	return (str);
}

int		print_nbr(t_handler *handler, char *nbr)
{
	int len;
	int nlen;
	int i;

	if (nbr == NULL)
		return (-1);
	nlen = ft_strlen(nbr);
	i = -1;
	if (handler->flags.justify)
		ft_putstr(nbr);
	if (handler->field_width > nlen)
	{
		len = handler->field_width;
		while (++i < (len - nlen))
		{
			if (handler->flags.zero && !handler->flags.justify)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else
		len = nlen;
	if (!handler->flags.justify)
		ft_putstr(nbr);
	ft_strdel(&nbr);
	return (len);
}


