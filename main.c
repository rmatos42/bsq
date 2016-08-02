/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 16:31:31 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/01 16:35:31 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

#define BUF_SIZE 100000

#include <stdio.h>
int		main(void)
{
	char *buf;
	int ret;
	int i;
	t_grid *grid;
	t_dynamic_result *dyn_arr;

	i = 0;
	buf = malloc(BUF_SIZE + 1);
	while (i < (BUF_SIZE + 1))
		buf[i++] = '\0';
	while ((ret = (read(0, buf, BUF_SIZE)) > 0))
		buf += ret;
	grid = set_grid_qualities(buf);
	i = 0;
	while (grid->table[i] != 0)
		printf("%s\n", grid->table[i++]);
	dyn_arr = dynamic_array(grid);
	int ix = 0;
	int iy = 0;
	while (iy < grid->rows)
	{
		ix = 0;
		while (ix < grid->cols)
			printf("%i ", dyn_arr->num_grid[iy][ix++]);
		printf("\n");
		iy++;
	}
	return (0);
}
