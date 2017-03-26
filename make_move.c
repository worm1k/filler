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

/*
** @return distance to the closest opponent char
** -1 if cant insert;
*/

void		circle_traverse(t_data *plat, t_data *piec, int y, int x)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 2
	while (1)
	{
		while(i < k)
		{
			if (try_insert(plat, piec, y - k / 2, x - k / 2 + i))
			{
				fprintf(f, "INSERTED [%d][%d]\n", i, j);
				printf("%d %d\n", i, j);
				fflush(stdout);
				return ;
			}
			i++;
		}
		k += 2;
	}
}

int			try_insert(t_data *plat, t_data *piec, int y, int x)
{
	int		over;
	int		i;
	int		j;

	i = 0;
	over = 0;
	while (i < piec->y)
	{
		j = 0;
		while (j < piec->x)
		{
			if (piec->map[i][j] == '*')
			{
				if (plat->map[y + i][x + j] == plat->c)
				{
					if (++over == 2)
						return (0);
				}
				else if (plat->map[y + i][x + j] == plat->opp)
					return (0);
			}
			j++;
		}
		i++;
	}

	if (over == 1)
		return (1);
	else
		return (0);
}

void		make_move(t_data *plat, t_data *piec)
{
	int		i;
	int		j;

	i = 0;
	while(i + piec->y - 1 < plat->y)
	{
		j = 0;
		while (j + piec->x - 1 < plat->x)
		{
			if (try_insert(plat, piec, i, j))
			{
				fprintf(f, "INSERTED [%d][%d]\n", i, j);
				printf("%d %d\n", i, j);
				fflush(stdout);
				return ;
			}
			j++;
		}
		i++;
	}
}
