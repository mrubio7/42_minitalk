/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:22:35 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/21 16:39:54 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, unsigned int n)
{
	char	*dest;

	dest = str;
	while (n)
	{
		*dest = c;
		dest++;
		n--;
	}
	return (str);
}