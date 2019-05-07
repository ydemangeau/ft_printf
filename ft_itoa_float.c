/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:41:50 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 10:42:10 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
