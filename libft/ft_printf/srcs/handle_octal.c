#include "../include/printf.h"

int			handle_octal(va_list *args, t_handler *handler)
{
	uintmax_t	arg;
	char	*pref;

	arg = va_arg(*args, uintmax_t);
	if (handler->precision >= 0)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width -1;
	if (handler->flags.prefix)
		pref = "0";
	else
		pref = "";
	return (print_nbr(handler, get_nbr(handler, arg, pref, 8)));
}
