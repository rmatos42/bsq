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
	fd = 0 + 1;
	raw_input = (char *)malloc(sizeof(char) * 1);
	raw_input[0] = '\0';
	while ((bytes_read = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		raw_input = buf_cat(raw_input, buf);
	}
	print_result(dynamic_array(set_grid_qualities(raw_input)));
	return (0);
}
