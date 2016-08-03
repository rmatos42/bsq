/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 19:18:15 by rmatos            #+#    #+#             */
/*   Updated: 2016/08/02 19:18:20 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_head.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*buf_cat(char *buf1, char *buf2)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buf1) + ft_strlen(buf2)) + 1);
	*tmp = '\0';
	ft_strcat(tmp, buf1);
	ft_strcat(tmp, buf2);
	free(buf1);
	return (tmp);
}
