#include "../include/printf.h"
#include "../include/struct.h"


int	handle_int(va_list *args, t_handler *handler)
{
	int		arg;
	char	*pref;

	arg = va_arg(*args, int);
	if (handler->flags.sign && arg > 0)
		pref = "+";
	else
		pref = "";
	ft_putstr(pref);
	
	
	ft_putnbr(arg);
	return (1);
}


