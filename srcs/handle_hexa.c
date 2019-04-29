#include "../include/printf.h"
#include "../include/struct.h"

int			handle_hexa(const char **format, va_list *args, t_handler *handler)
{
	uintmax_t	arg;
	char	*pref;
	char	*str;
	int i;

	i = -1;
	arg = cast_unsigned_lenght(args, handler);
	if (handler->precision >= 0)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width -2;
	if (handler->flags.prefix)
	{
		if (**format == 'x')
			pref = "0x";
		if (**format == 'X')
			pref = "0X";
	}
	else
		pref = "";
	str = get_nbr(handler, arg, pref, 16);
	if (**format == 'x')
	{
		while (str[++i])
		{
			if (ft_isalpha(str[i]))
				str[i] = ft_tolower(str[i]);
		}
	}
	return (print_nbr(handler, str));
}
