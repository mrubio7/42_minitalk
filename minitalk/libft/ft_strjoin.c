/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:30:49 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/21 16:32:59 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		total;
	int		x;
	int		z;

	z = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(total + 1);
	if (res == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		res[x] = s1[x];
		x++;
	}
	while (s2[z] != '\0')
	{
		res[x + z] = s2[z];
		z++;
	}
	res[x + z] = '\0';
	return (res);
}
