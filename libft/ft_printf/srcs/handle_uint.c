#include "../include/printf.h"

int		handle_uint(va_list *args, t_handler *handler)
{
	uintmax_t	arg;

	handler->flags.sign = 0;
	handler->flags.space = 0;
	arg = cast_unsigned_lenght(args, handler);
	return (print_nbr(handler, get_nbr(handler, arg, "", 10)));
}


