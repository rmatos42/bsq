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

#define BUF_SIZE 32000

#include <stdio.h>
int		main(void)
{
	char *raw_input;
	int bytes_read;
	int	fd;
	char buf[BUF_SIZE];
	t_dynamic_result *dyn_arr;
	fd = 0 + 1;
	raw_input = (char *)malloc(sizeof(char) * 1);
	raw_input[0] = '\0';
	while ((bytes_read = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		raw_input = buf_cat(raw_input, buf);
	}
	dyn_arr = dynamic_array(raw_input);
	printf("rows: %i\n", dyn_arr->rows);
	printf("cols: %i\n", dyn_arr->cols);
	printf("empty: %c\n", dyn_arr->empty);
	printf("obstacle: %c\n", dyn_arr->obstacle);
	printf("square: %c\n", dyn_arr->square);
	printf("%i\n", dyn_arr->max_square_size);
	print_result(dyn_arr);
	int ix = 0;
	int iy = 0;
	while(iy < dyn_arr->rows)
	{
		ix = 0;
		while (ix < dyn_arr->cols)
			printf("%i", dyn_arr->num_grid[iy][ix++]);
		printf("\n");
		iy++;
	}
	return (0);
}
