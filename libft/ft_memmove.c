/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:07:28 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 14:07:29 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t n)
{
	char				*d;
	char				*s;
	size_t				i;

	d = (char *)dst;
	s = (char *)src;
	if (src > dst)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dst);
}
