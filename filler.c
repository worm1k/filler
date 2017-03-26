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

void		o_or_x(t_data *plat)
{
	char	*line;

	get_next_line(fd, &line);
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
	fprintf(f, "[%c]\n", plat->c);
	ft_strdel(&line);
}

void		read_xy(int *x, int *y)
{
	char	*line;
	int		i;

	get_next_line(fd, &line);
	i = 0;
	while (line[i] < '0' || '9' < line[i])
		i++;
	*x = 0;
	*y = 0;
	while (line[i] > '0' && '9' > line[i])
		*y = *y * 10 + line[i++] - '0';
	i++;
	while (line[i] > '0' && '9' > line[i])
		*x = *x * 10 + line[i++] - '0';
	fprintf(f, "[%d][%d]\n", *y, *x);
	fflush(f);
	ft_strdel(&line);
}

void		plateau_skip(char **line)
{
	if (!ft_strstr(*line, "Plateau"))
		return (ft_strdel(line));
	ft_strdel(line);
	get_next_line(fd, line);
	ft_strdel(line);
}

void		alloc_map(int x, int y, char ***map)
{
	char	*line;
	int		i;

	i = 0;
	*map = (char **)malloc(sizeof(char *) * y + 1);
	(*map)[y] = 0;
	while (i < y)
	{
		(*map)[i] = (char *)malloc(sizeof(char) * (x + 1));
		(*map)[i][x] = '\0';
		i++;
	}
}

void		read_map(int x, int y, char **map)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	while(i < y)
	{
		get_next_line(fd, &line);
		k = 0;
		while (!ft_strchr(".OX", line[k]))
		{
			k++;
		}
		j = 0;
		while (j < x)
		{
			map[i][j] = line[k];
			j++;
			k++;
		}
		fprintf(f, "%03d %s\n", i, map[i]);
		ft_strdel(&line);
		i++;
	}
}

void		read_piece(int x, int y, char **map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while(i < y)
	{
		get_next_line(fd, &line);
		j = 0;
		while (j < x)
		{
			map[i][j] = line[j];
			j++;
		}
		fprintf(f, "%s\n", map[i]);
		ft_strdel(&line);
		i++;
	}
}

int			main()
{
	int		i;
	t_data	*plat;
	t_data	*piec;
	char	*line;

	plat = (t_data *)malloc(sizeof(t_data));
	piec = (t_data *)malloc(sizeof(t_data));
	f = fopen("debug.log", "w");
	fd = 0;
	o_or_x(plat);
	read_xy(&plat->x, &plat->y);
	alloc_map(plat->x, plat->y, &plat->map);
	while (get_next_line(fd, &line) > 0)
	{
		plateau_skip(&line);
		read_map(plat->x, plat->y, plat->map);
		read_xy(&piec->x, &piec->y);
		alloc_map(piec->x, piec->y, &piec->map);
		read_piece(piec->x, piec->y, piec->map);
		make_move(plat, piec);
	}
	fclose(f);
	close(fd);
	return (0);
}
