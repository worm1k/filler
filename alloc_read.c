/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:55:34 by abykov            #+#    #+#             */
/*   Updated: 2016/11/21 10:55:36 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		clean_piece(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->py)
	{
		ft_strdel(&data->piece[i]);
		i++;
	}
	free(data->piece);
	data->piece = 0;
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
	while (i < data->y)
	{
		get_next_line(0, &line);
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
		ft_strdel(&line);
		i++;
	}
}

void		read_piece(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	data->sum = 2147483647;
	data->xx = -1;
	data->yy = -1;
	i = 0;
	while (i < data->py)
	{
		get_next_line(0, &line);
		j = 0;
		while (j < data->px)
		{
			data->piece[i][j] = line[j];
			j++;
		}
		ft_strdel(&line);
		i++;
	}
}
