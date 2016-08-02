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

t_dynamic_result *dynamic_array(t_grid *grid)
{
	t_dynamic_result *dyn_grid;
	int ix;
	int iy;

	dyn_grid->max_square_size = 1;
	iy = 0;
	dyn_grid->num_grid = (int **)malloc(sizeof(int *) * grid->rows);
	while (iy < grid->rows)
	{
		ix = 0;
		dyn_grid->num_grid[iy] = (int *)malloc(sizeof(int) * grid->cols);
		while (ix < grid->cols)
		{
			if (ix == 0 || iy == 0)
			{
				if (grid->table[iy][ix] == grid->empty)
					dyn_grid->num_grid[iy][ix] = 1;
				else if (grid->table[iy][ix] == grid->obstacle)
					dyn_grid->num_grid[iy][ix] = 0;
			}
			else if (grid->table[iy][ix] == grid->empty)
			{
				dyn_grid->num_grid[iy][ix] = get_min(dyn_grid->num_grid, ix, iy) + 1;
				if (dyn_grid->num_grid[iy][ix] > dyn_grid->max_square_size)
					dyn_grid->max_square_size = dyn_grid->num_grid[iy][ix];
			}
			else
				dyn_grid->num_grid[iy][ix] = 0;
			ix++;
		}
		iy++;
	}
	return (dyn_grid);
}

