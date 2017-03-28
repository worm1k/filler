/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 256
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	struct s_lst	*next;
	char			*buf;
	int				fd;
}					t_lst;
int					get_next_line(const int fd, char **line);

typedef	struct		s_data
{
	char			c;
	char			opp;
	int				x;
	int				y;
	int				px;
	int				py;
	char			**map;
	char			**piece;
	int				**prior;
	int				xx;
	int				yy;
	int				sum;
}					t_data;

void				make_move(t_data *data);
void				build_priority(t_data *data);
void				alloc_map(t_data *data);
void				alloc_piece(t_data *data);
void				read_map(t_data *data);
void				read_piece(t_data *data);
void				ft_printf(int y, int x);
void				clean_piece(t_data *data);

#endif
