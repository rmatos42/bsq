/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 02:02:07 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/02 02:02:10 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

int		get_min(int **dynamic, int x, int y)
{
	int smallest;

	smallest = dynamic[y - 1][x];
	if (dynamic[y - 1][x - 1] < smallest)
		smallest = dynamic[y - 1][x - 1];
	if (dynamic[y][x - 1] < smallest)
		smallest = dynamic[y][x - 1];
	return (smallest);
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

t_dynamic_result	*dynamic_array(char *buf)
{
	t_dynamic_result *dyn_arr;
	int x;
	int y;
	int past_first;
	int	i;

	i = -1;
	past_first = 0;
	dyn_arr = set_qualities(buf);
	y = 0;
	x = 0;
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n')
		{
			if (past_first)
				dyn_arr->num_grid[++y] = (int *)malloc(sizeof(int) * dyn_arr->cols);
			else
				past_first = 1;
			x = 0;
		}
		else if (past_first)
			set_num(dyn_arr, buf[i], x++, y);
	}
	return (dyn_arr);
}

void				set_num(t_dynamic_result *dyn_arr, char c , int x, int y)
{
	if (c == dyn_arr->obstacle)
		dyn_arr->num_grid[y][x] = 0;
	else if (c == dyn_arr->empty)
	{
		if (x == 0 || y == 0)
			dyn_arr->num_grid[y][x] = 1;
		else
			dyn_arr->num_grid[y][x] = get_min(dyn_arr->num_grid, x, y) + 1;		
		if (dyn_arr->num_grid[y][x] > dyn_arr->max_square_size)
		{
			dyn_arr->x_loc = x;
			dyn_arr->y_loc = y;
			dyn_arr->max_square_size = dyn_arr->num_grid[y][x];
		}
	}
}

t_dynamic_result	*set_qualities(char *buf)
{
	int i;
	int j;
	int len;
	t_dynamic_result *dyn_arr;

	dyn_arr = malloc(sizeof(t_dynamic_result));
	j = 1;
	len = 0;
	while (buf[len] != '\n')
		len++;
	i = len - 4;
	dyn_arr->rows = 0;
	while (i >= 0)
	{
		dyn_arr->rows += (buf[i--] - '0') * j;
		j *= 10;
	}
	dyn_arr->max_square_size = 0;
	dyn_arr->square = buf[len - 1];
	dyn_arr->obstacle = buf[len - 2];
	dyn_arr->empty = buf[len - 3];
	dyn_arr->cols = get_xdimen(buf);
	dyn_arr->num_grid = (int **)malloc(sizeof(int *) * dyn_arr->rows);
	dyn_arr->num_grid[0] = (int *)malloc(sizeof(int) * dyn_arr->cols);
	return (dyn_arr);
}
