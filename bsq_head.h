/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 16:38:23 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/01 16:43:12 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEAD_H
# define BSQ_HEAD_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_grid
{
	int				rows;
	int				cols;
	char			empty;
	char			obstacle;
	char			square;
	char			**table;
}					t_grid;

typedef struct		s_dynamic_result
{
	int				**num_grid;
	int				max_square_size;
}					t_dynamic_result;

t_dynamic_result *dynamic_array(t_grid *grid);
int		get_min(int **dynamic, int x, int y);
t_grid		*set_grid_qualities(char *buf);
int		get_xdimen(char *buf);
int		get_ydimen(char *buf);
char	**get_grid(char *buf, int x, int y);

#endif
