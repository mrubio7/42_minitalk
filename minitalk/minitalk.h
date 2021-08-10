/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:17:03 by mrubio            #+#    #+#             */
/*   Updated: 2021/08/04 07:37:27 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int				ft_atoi(const char *str);
unsigned int	ft_strlen(const char *str);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
char			*ft_strdup(const char *src);

typedef struct	s_data
{
	char		c;
	int			bw;
}				t_data;
