/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/08/11 00:06:53 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_char_from_bits(int sigusr)
{
	static char	c = 0;
	static int	i = 8;

	if (sigusr == SIGUSR1)
		c |= (0 << --i);
	else if (sigusr == SIGUSR2)
		c |= (1 << --i);
	if (i == 0)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 8;
		c = 0;
	}
}

void	get_sig(int sigusr)
{
	if (sigusr == SIGUSR1 || sigusr == SIGUSR2)
		get_char_from_bits(sigusr);
	else
		exit(1);
}

int main()
{
	pid_t	process_id;
	
	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	printf("\n...Waiting to receive data...\n\n");
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	while(1)
		pause();
	return 0;
}

