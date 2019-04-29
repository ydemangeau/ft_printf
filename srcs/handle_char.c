#include "../include/printf.h"
#include "../include/struct.h"

int		handle_char(va_list *args, t_handler *handler)
{
	int arg;
	int len;
	
	arg = va_arg(*args, int);
	len = 0;
	while (++len != handler->field_width && handler->field_width)
		ft_putchar(' ');
	ft_putchar(arg);
	
	return (len);
}
