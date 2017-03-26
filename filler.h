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

FILE				*f;
int					fd;
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
	char			**map;
}					t_data;

void				make_move(t_data *plat, t_data *piec);

#endif