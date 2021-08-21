/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:35:26 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/21 16:48:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int item, unsigned int size)
{
	char	*res;
	int		total;
	int		x;

	total = item * size;
	res = malloc(total);
	if (!res)
		return (NULL);
	x = 0;
	while (total--)
	{
		res[x] = '\0';
		x++;
	}
	return ((void *)res);
}
