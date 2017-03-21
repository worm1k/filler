/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*res;
	size_t	a;
	size_t	b;

	if (!s)
		return (NULL);
	a = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	if (s[a] == '\0')
		return (ft_strnew(0));
	b = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b--;
	res = ft_strsub(s, a, b - a + 1);
	return (res);
}
