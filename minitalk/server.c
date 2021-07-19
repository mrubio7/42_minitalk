/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/19 16:11:07 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void *putstr()
{
	write(1, "1", 1);
	return (0);
}

void *putstr2()
{
	write(1, "0", 1);
	return (0);
}

int main()
{
	pid_t	process_id;

	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	while (1)
	{
		signal(SIGUSR1, (void *)putstr);
		signal(SIGUSR2, (void *)putstr2);
		pause();
		printf("\n...Waiting to receive data...\n\n");
	}
	return 0;
}

