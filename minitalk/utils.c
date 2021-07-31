/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:00:04 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/31 17:50:26 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				x;
	long long int	num;
	long long int	sig;

	x = 0;
	sig = 1;
	num = 0;
	while (str[x] == 32 || str[x] == 10 || str[x] == 9
		|| str[x] == 12 || str[x] == 13 || str[x] == 11)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sig = -1;
		x++;
	}
	while (str[x] != '\0')
	{
		if (str[x] < 48 || 57 < str[x])
			return (num * sig);
		else
			num = (num * 10) + (str[x] - '0');
		x++;
	}
	return (num * sig);
}

unsigned int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (*str != '\0')
	{
		x++;
		str++;
	}
	return (x);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*s;
	char		*d;

	if (!dest && !src)
		return (NULL);
	s = (char *)src;
	d = dest;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	int		x;

	x = ft_strlen(src) + 1;
	s = malloc(x);
	if (s == NULL)
		return (NULL);
	if (src == NULL)
	{
		free(s);
		return (NULL);
	}
	ft_memcpy(s, src, x);
	return (s);
}
