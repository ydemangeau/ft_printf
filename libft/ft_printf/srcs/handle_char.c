#include "../include/printf.h"

int		handle_char(va_list *args, t_handler *handler)
{
	int arg;
	int len;
	
	arg = va_arg(*args, int);
	len = 1;
	while (len != handler->field_width && handler->field_width && !handler->flags.justify)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putchar(arg);
	while(handler->flags.justify && len != handler->field_width && handler->field_width)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}
