/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:28:38 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/21 16:39:32 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		x;

	current = lst;
	x = 0;
	while (current != NULL)
	{
		x += 1;
		current = current->next;
	}
	return (x);
}
