/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/08 12:17:04 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*putstr()
{
	printf("Señal recibida!\n");
	return 0;
}

int	convert_signal()
{
	struct sigaction act;

	act.sa_handler = (void *)putstr;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return (sigaction(SIGUSR1, &act, NULL));
}

int	main()
{
	pid_t process_id;

	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	while(1)
	{
		convert_signal();
		printf("...Waiting to receive data...\n");
		pause();
	}
	return 0;
}

