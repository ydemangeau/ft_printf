#include "../include/printf.h"

int		handle_int(va_list *args, t_handler *handler)
{
	intmax_t		arg;
	char	*pref;

	if (handler->precision >= 0 || handler->flags.justify)
		handler->flags.zero = 0;
	else if (handler->flags.zero)
		handler->precision = handler->field_width -1;
	arg = cast_lenght(args, handler);
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
	return (print_nbr(handler, get_nbr(handler, arg, pref, 10)));
}


