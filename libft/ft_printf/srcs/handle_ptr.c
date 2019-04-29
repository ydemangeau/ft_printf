#include "../include/printf.h"

int		handle_ptr(va_list *args, t_handler *handler)
{
	uintmax_t arg;
	char *pref;
	char *str;
	int i;

	handler->precision = -1;
	i = -1;
	pref = "0x";
	arg = cast_unsigned_lenght(args, handler);
	str = get_nbr(handler, arg, pref, 16);
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_tolower(str[i]);
	}
	return (print_nbr(handler,str));
}



