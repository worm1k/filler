/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ftt_strdup(char const *s, char c)
{
	char		*res;
	size_t		i;
	size_t		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] != c && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	ftt_getsize(char const *s, char c)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			size++;
		while (s[i] != c && s[i])
			i++;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ftt_getsize(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			res[j++] = ftt_strdup(s + i, c);
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = (NULL);
	return (res);
}
