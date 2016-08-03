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
	int ix;
	int iy;
	int past_first;
	int	i;
	clock_t start, end;

	i = 0;
	past_first = 0;
	dyn_arr = set_qualities(buf);
	iy = 0;
	ix = 0;
	dyn_arr->num_grid = (int **)malloc(sizeof(int *) * dyn_arr->rows);
	dyn_arr->num_grid[0] = (int *)malloc(sizeof(int) * dyn_arr->cols);
	start = clock();
	while (buf[i] != '\0')
	{
		if (!past_first && buf[i] == '\n')
		{
			ix = 0;
			past_first = 1;
		}
		else if (past_first && buf[i] == '\n')
		{
			ix = 0;
			dyn_arr->num_grid[++iy] = (int *)malloc(sizeof(int) * dyn_arr->cols);
		}
		else if (past_first)
		{
			if (ix == 0 || iy == 0)
			{
				if (buf[i] == dyn_arr->obstacle)
					dyn_arr->num_grid[iy][ix] = 0;
				if (buf[i] == dyn_arr->empty)
					dyn_arr->num_grid[iy][ix] = 1;
			}
			else
			{
				if (buf[i] == dyn_arr->obstacle)
					dyn_arr->num_grid[iy][ix] = 0;
				if (buf[i] == dyn_arr->empty)
				{
					dyn_arr->num_grid[iy][ix] = get_min(dyn_arr->num_grid, ix, iy) + 1;
					if (dyn_arr->num_grid[iy][ix] > dyn_arr->max_square_size)
					{
						dyn_arr->x_loc = ix;
						dyn_arr->y_loc = iy;
						dyn_arr->max_square_size = dyn_arr->num_grid[iy][ix];
					}
				}
			}
		}
		ix++;
		i++;

	}
	end = clock();
	printf("time: %f\n", (end-start)/(double)CLOCKS_PER_SEC);
;	return (dyn_arr);
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
	dyn_arr->max_square_size = 1;
	dyn_arr->square = buf[len - 1];
	dyn_arr->obstacle = buf[len - 2];
	dyn_arr->empty = buf[len - 3];
	dyn_arr->cols = get_xdimen(buf);
	return (dyn_arr);
}
