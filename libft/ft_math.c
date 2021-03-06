/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_max(int a, int b)
{
	return ((a > b) ? (a) : (b));
}

int			ft_min(int a, int b)
{
	return ((a < b) ? (a) : (b));
}

int			ft_abs(int a)
{
	if (a == -2147483648)
		return (a);
	return ((a < 0) ? (-a) : (a));
}
