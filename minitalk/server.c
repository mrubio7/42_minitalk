/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/08/10 23:45:40 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void get_bit(int bit)
{
	if (bit == SIGUSR1)
		write(1, "1", 1);
	else if (bit == SIGUSR2)
		write(1, "0", 1);
}

int main()
{
	pid_t	process_id;
	
	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	printf("\n...Waiting to receive data...\n\n");
	while(1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
		pause();
	}
	return 0;
}

