#include "libft.h"
#include <stdio.h>

char	*ft_restrcat(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	if (*dst && src)
	{
		*dst = ft_strjoin(*dst, src);
		free(tmp);
	}
	else if (src)
	{
		*dst = ft_strdup(src);
		free(tmp);
	}
	return (*dst);
}
/*
static int		count(double temp, int integer)
{
	int i;

	i = 1;
	while (integer >= 10)
	{
		integer = integer /10;
		i++;
	}
	return i;
}
*/
char	*ft_itoa_float(long double nb, int base)
{
	int		integer;
	int		decimal;
	double	temp;
	char	*tmp;
	char	*new;

	integer = nb / 1;
	temp = nb - integer;
	decimal = -1;
	while (++decimal < 9)
	{
		temp *= 10;
	}
	decimal = (int)(temp + 0.5);
	tmp = ft_itoa_base(integer, base);
	new = ft_strjoin(tmp, ".");
	ft_strdel(&tmp);
	tmp = ft_itoa_base(decimal, base);
	ft_restrcat(&new, tmp);
	ft_strdel(&tmp);
	return (new);
}
/*
int main()
{
	printf("str = %s\n\n", ft_itoa_float(12.5300156, 10));
	printf("str = %s\n", ft_itoa_float(12.26, 10));
	return (0);
}
*/

