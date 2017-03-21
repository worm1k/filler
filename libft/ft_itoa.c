/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftt_getrank(int n)
{
	int			negative;
	size_t		res;

	negative = (n < 0) ? 1 : 0;
	if (n == 0)
		return (1);
	res = 0;
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res + negative);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*res;

	i = ftt_getrank(n) - 1;
	res = ft_strnew(i + 1);
	if (!res)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (n == 0)
		return (ft_strcpy(res, "0"));
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n)
	{
		res[i--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
