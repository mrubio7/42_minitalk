/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 09:20:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/22 14:24:06 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *str1, const void *str2, unsigned int n)
{
	int	x;

	x = 0;
	if (!str1 && !str2)
		return (NULL);
	if (str2 <= str1)
	{
		while ((int)n--)
		{
			(*(char *)(str1 + n)) = (*(const char *)(str2 + n));
			x++;
		}
	}
	else
	{
		while ((int)n--)
		{
			*(char *)(str1 + x) = *(const char *)(str2 + x);
			x++;
		}
	}
	return (str1);
}
