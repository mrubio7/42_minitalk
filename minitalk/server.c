/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/09/28 21:59:26 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_bit(int bit)
{
	char		c;
	static char	letter = 0;
	static int	n = 7;

	c = 0;
	if (n >= 0)
	{
		if (bit == SIGUSR1)
			letter = letter | (1 << n);
		n--;
		if (n < 0)
		{
			if (letter == 0)
				write(1, "\n", 1);
			else
				write(1, &letter, 1);
			n = 7;
			letter = 0;
		}
	}
}

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("Process ID (PID): %d\n", process_id);
	ft_printf("\n...Waiting to receive data...\n\n");
	while (1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
		pause();
	}
	return (0);
}
