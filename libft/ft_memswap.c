/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:45:10 by abykov            #+#    #+#             */
/*   Updated: 2016/11/22 18:45:10 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memswap(void *a, void *b, size_t size)
{
	void	*temp;

	temp = malloc(size);
	ft_memmove(temp, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, temp, size);
	free(temp);
}
