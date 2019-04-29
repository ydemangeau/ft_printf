#include "../include/printf.h"
#include "../include/struct.h"


int		handle_uint(va_list *args, t_handler *handler)
{
	uintmax_t	arg;

	handler->flags.zero = 0;
	handler->flags.sign = 0;
	handler->flags.space = 0;
	handler->flags.justify = 0;
	arg = cast_unsigned_lenght(args, handler);
	return (print_nbr(handler, get_nbr(handler, arg, "", 10)));
}


