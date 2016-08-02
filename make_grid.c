/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 16:35:55 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/01 16:38:08 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

char	**get_grid(char *buf, int x, int y)
{
	char	**grid;
	int		ix;
	int		iy;
	int		i;
	int		past_first;

	i = -1;
	ix = 0;
	iy = 0;
	past_first = 0;
	grid = malloc(sizeof(char *) * (y + 1));
	grid[iy] = (char *)malloc(sizeof(char) * x + 1);
	while (iy < y)
	{
		if (buf[i] == '\n' && past_first)
		{
			grid[iy][ix] = '\0';
			grid[++iy] = (char *)malloc(sizeof(char) * x + 1);
			ix = 0;
		}
		else if (buf[i] == '\n')
			past_first = 1;
		else if (past_first)
			grid[iy][ix++] = buf[i];
		i++;
	}
	grid[y] = 0;
	return (grid);
}

int		get_xdimen(char *buf)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (y < 2)
	{
		if (buf[i] == '\n')
			y++;
		else if (y == 1)
			x++;
		i++;
	}
	return (x);
}

int		get_ydimen(char *buf)
{
	int i;
	int y;
	int past_first;

	i = 0;
	y = 0;
	past_first = 0;

	while (buf[i] != '\0')
	{
		if (past_first && buf[i] == '\n')
			y++;
		else if (buf[i] == '\n')
			past_first = 1;
		i++;
	}
	return(y);
}

t_grid		*set_grid_qualities(char *buf)
{
	int i;
	int	j;
	int len;
	t_grid *grid;

	j = 1;
	grid = malloc(sizeof(t_grid));
	len = 0;
	while (buf[len] != '\n')
		len++;
	i = len - 4;
	grid->square = buf[len - 1];
	grid->obstacle = buf[len - 2];
	grid->empty = buf[len - 3];
	grid->rows = get_xdimen(buf);
	grid->table = get_grid(buf, grid->cols, grid->rows);
	return (grid);
}