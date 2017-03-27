/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_priority.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:34 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 10:55:36 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_min(int a, int b)
{
	return ((a < b) ? (a) : (b));
}

int			ft_abs(int a)
{
	if (a == -2147483648)
		return (2147483647);
	return ((a < 0) ? (-a) : (a));
}


void		calc_rel_prior(t_data *data, int ii, int jj)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			if (data->map[i][j] != data->opp)
			{
				temp = ft_abs(i - ii) + ft_abs(j - jj);
				data->prior[i][j] = ft_min(temp, data->prior[i][j]);
			}
			j++;
		}
		i++;
	}
}

void		build_priority(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			if (data->map[i][j] == data->opp)
			{
				calc_rel_prior(data, i, j);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			if (data->map[i][j] == data->opp)
			{
				fprintf(f, "   X");
			}
			else
				fprintf(f, "%4d", data->prior[i][j]);
			j++;
		}
		i++;
				fprintf(f, "\n");
	}
}