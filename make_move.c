/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:34 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 10:55:36 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	extra_line(int *i, int *over)
{
	*i = 0;
	*over = 0;
}

int			try_insert(t_data *data, int y, int x)
{
	int		over;
	int		i;
	int		j;

	extra_line(&i, &over);
	while (i < data->py)
	{
		j = 0;
		while (j < data->px)
		{
			if (data->piece[i][j] == '*')
			{
				if (data->map[y + i][x + j] == data->c)
				{
					if (++over == 2)
						return (0);
				}
				else if (data->map[y + i][x + j] == data->opp)
					return (0);
			}
			j++;
		}
		i++;
	}
	return ((over == 1) ? (1) : (0));
}

void		check_sum(t_data *data, int yy, int xx)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	temp = 0;
	while (i < data->py)
	{
		j = 0;
		while (j < data->px)
		{
			if (data->piece[i][j] == '*')
				temp += data->prior[yy + i][xx + j];
			j++;
		}
		i++;
	}
	if (temp < data->sum)
	{
		data->sum = temp;
		data->xx = xx;
		data->yy = yy;
	}
}

void		make_move(t_data *data)
{
	int		i;
	int		j;

	build_priority(data);
	i = 0;
	while (i + data->py - 1 < data->y)
	{
		j = 0;
		while (j + data->px - 1 < data->x)
		{
			if (try_insert(data, i, j))
			{
				check_sum(data, i, j);
			}
			j++;
		}
		i++;
	}
	ft_printf(data->yy, data->xx);
}
