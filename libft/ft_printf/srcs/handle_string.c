#include "../include/printf.h"

int		handle_string(va_list *args, t_handler *handler)
{
	char *arg;
	char *str;
	int len;
	int slen;

	handler->flags.zero = 0;
	arg = va_arg(*args, char*);
	if (arg == NULL)
	{
		ft_putstr("(null)");
		return (6);//str = "(null)";
	}
	slen = ft_strlen(arg);
	if (handler->precision == 0)
		len = 0;
	else if (handler->precision > 0)
		len = handler->precision;
	else
		len = slen;
	str = ft_strsub(arg, 0 ,len);
	return (print_nbr(handler, str));
}
