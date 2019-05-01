#include "libft.h"

void	ft_putnstr(const char *s, int n)
{
	while (n--)
	{
		ft_putchar(*s);
		s++;
	}
}
