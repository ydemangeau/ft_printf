#include "../include/printf.h"
#include "../include/struct.h"

int		handle_string(va_list *args, t_handler *handler)
{
	char *arg;
	char *str;
	int len;
	int slen;

	arg = va_arg(*args, char*);
	slen = ft_strlen(arg);
	if (str == NULL)
		str = "(null)";
	if (handler->precision == 0)
		len = 0;
	else if (handler->precision > 0)
		len = handler->precision;
	else
		len = slen;
	str = ft_strsub(arg, 0 ,len);
	return (print_nbr(handler, str));
}
