/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:25:34 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/02 17:25:36 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

void	print_result(t_dynamic_result *dyn_arr, t_grid *grid)
{
	int ix;
	int iy;

	iy = 0;
	while (iy < grid->rows)
	{
		ix = 0;
		while (ix < grid->cols)
			ft_putchar(get_char(dyn_arr, grid, ix++, iy));
		ft_putchar('\n');
		iy++;
	}
}

char	get_char(t_dynamic_result *dyn_arr, t_grid *grid, int x, int y)
{
	if (is_big_square(dyn_arr, x, y))
		return (grid->square);
	else if (dyn_arr->num_grid[y][x] > 0)
		return (grid->empty);
	else
		return (grid->obstacle);
}

int		is_big_square(t_dynamic_result *dyn_arr, int x, int y)
{
	if(x > (dyn_arr->x_loc - dyn_arr->max_square_size)
		&& y > (dyn_arr->y_loc - dyn_arr->max_square_size)
		&& x <= dyn_arr->x_loc  && y <= dyn_arr->y_loc)
		return (1);
	return(0);
}
