/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int	i;

	ft_strtolower(s);
	i = 1;
	if (ft_islower(s[0]))
		s[0] -= 32;
	while (s[i])
	{
		if (!ft_isalnum(s[i]) && ft_islower(s[i + 1]))
			s[i + 1] -= 32;
		i++;
	}
	return (s);
}
