/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:07:28 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 14:07:29 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)src;
	while (n > 0)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
		n--;
	}
	return (NULL);
}
