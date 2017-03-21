/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:07:41 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 16:07:42 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}
