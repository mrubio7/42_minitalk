/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:05:14 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/08 11:26:16 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void *pinta()
{
	printf("Señal recibida!\n");
	return 0;
}

int main()
{
	pid_t process_id;
	void *pintar;

	pintar = pinta;
	process_id = getpid();
	printf("Process ID (PID): %d\n", process_id);
	while(1)
	{
		signal(SIGUSR1, pintar);
		printf("...Waiting to receive data...\n");
		pause();
	}
	return 0;
}

