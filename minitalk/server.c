/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/31 20:23:49 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void *is_one()
{
	write(1, "1", 1);
	return (0);
}

void *is_zero()
{
	write(1, "0", 1);
	return (0);
}

int main()
{
	pid_t	process_id;

	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	printf("\n...Waiting to receive data...\n\n");
	while(1)
	{
		signal(SIGUSR1, (void *)is_one);
		signal(SIGUSR2, (void *)is_zero);
		pause();
	}
	return 0;
}

