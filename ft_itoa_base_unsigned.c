/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:42:18 by ydemange          #+#    #+#             */
/*   Updated: 2019/05/07 10:43:19 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(unsigned long long int n, unsigned int base)
{
	int		i;

	i = 1;
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_unsigned(unsigned long long int value, int base)
{
	int		i;
	char	*nbr;

	i = count(value, (unsigned int)base);
	if (!(nbr = (char*)ft_memalloc(sizeof(nbr) * i)))
		return (NULL);
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
