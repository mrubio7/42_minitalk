/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:35:00 by mrubio            #+#    #+#             */
/*   Updated: 2021/06/21 16:31:44 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	while (*lst != NULL)
	{
		curr = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(curr);
	}
}
