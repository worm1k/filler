/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:34 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 10:55:36 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	o_or_x(t_data *plat)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strnstr(line, "$$$ exec p1", 11))
	{
		plat->c = 'O';
		plat->opp = 'X';
	}
	else
	{
		plat->c = 'X';
		plat->opp = 'O';
	}
	ft_strdel(&line);
}

static void	read_xy(int *x, int *y)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = 0;
	while (line[i] < '0' || '9' < line[i])
		i++;
	*x = 0;
	*y = 0;
	while ('0' <= line[i] && line[i] <= '9')
		*y = *y * 10 + line[i++] - '0';
	i++;
	while ('0' <= line[i] && line[i] <= '9')
		*x = *x * 10 + line[i++] - '0';
	ft_strdel(&line);
}

static void	plateau_skip(char **line)
{
	if (!ft_strstr(*line, "Plateau"))
		return (ft_strdel(line));
	ft_strdel(line);
	get_next_line(0, line);
	ft_strdel(line);
}

int			main(void)
{
	int		i;
	t_data	*data;
	char	*line;

	data = (t_data *)malloc(sizeof(t_data));
	o_or_x(data);
	read_xy(&data->x, &data->y);
	alloc_map(data);
	while (get_next_line(0, &line) > 0)
	{
		plateau_skip(&line);
		read_map(data);
		read_xy(&data->px, &data->py);
		alloc_piece(data);
		read_piece(data);
		make_move(data);
		clean_piece(data);
	}
	return (0);
}
