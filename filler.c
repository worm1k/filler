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

void		alloc_map(t_data *data)
{
	int		i;

	i = 0;
	data->map = (char **)malloc(sizeof(char *) * data->y + 1);
	data->prior = (int **)malloc(sizeof(int *) * data->y);
	data->map[data->y] = 0;
	while (i < data->y)
	{
		data->map[i] = (char *)malloc(sizeof(char) * (data->x + 1));
		data->prior[i] = (int *)malloc(sizeof(int) * (data->x));
		data->map[i][data->x] = '\0';
		i++;
	}
}

void		alloc_piece(t_data *data)
{
	int		i;

	i = 0;
	data->piece = (char **)malloc(sizeof(char *) * data->py + 1);
	data->piece[data->py] = 0;
	fprintf(f, "[%d][%d]\n", data->py, data->px);
	while (i < data->py)
	{
		data->piece[i] = (char *)malloc(sizeof(char) * (data->px + 1));
		data->piece[i][data->px] = '\0';
		i++;
	}
}

void		read_map(t_data *data)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	while(i < data->y)
	{
		get_next_line(fd, &line);
		k = 0;
		while (!ft_strchr(".OX", line[k]))
			k++;
		j = 0;
		while (j < data->x)
		{
			data->map[i][j] = line[k];
			data->prior[i][j] = 2147483647;
			j++;
			k++;
		}
		fprintf(f, "%03d %s\n", i, data->map[i]);
		ft_strdel(&line);
		i++;
	}
}

void		read_piece(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while(i < data->py)
	{
		get_next_line(fd, &line);
		j = 0;
		while (j < data->px)
		{
			data->piece[i][j] = line[j];
			j++;
		}
		fprintf(f, "%s\n", data->piece[i]);
		ft_strdel(&line);
		i++;
	}
}

int			main()
{
	int		i;
	t_data	*data;
	char	*line;

	data = (t_data *)malloc(sizeof(t_data));
	f = fopen("debug.log", "w");
	fd = 0;
	o_or_x(data);
	read_xy(&data->x, &data->y);
	alloc_map(data);
	while (get_next_line(fd, &line) > 0)
	{
		plateau_skip(&line);
		read_map(data);
		read_xy(&data->px, &data->py);
		alloc_piece(data);
		read_piece(data);
		build_priority(data);
		//delete_map and piece
	}
	fclose(f);
	close(fd);
	return (0);
}
