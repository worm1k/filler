/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	int i;
	int j;

	if (!n[0])
		return ((char *)h);
	i = 0;
	while (h[i] && i + ft_strlen(n) - 1 < len)
	{
		j = 0;
		while (h[i + j] == n[j])
		{
			if (n[j + 1] == '\0')
				return ((char *)&(h[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
