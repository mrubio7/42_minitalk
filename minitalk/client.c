/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:01 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/19 16:48:16 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sendbit(int PID, int b)
{
	if (b == 1)
		kill(PID, SIGUSR1);
	else
		kill(PID, SIGUSR2);
}

int	InitSend(int PID, const char *str)
{
	int	bit;
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		for (int bw = 7; bw >= 0; bw--)
		{
			bit = (str[x] >> bw) & 0000001;
			sendbit(PID, bit);
			printf("%i", bit);
		}
		x++;
	}
	return 0;
}

int	main(int argc, char *argv[])
{
	int		PID;
	pid_t	MyPID;

	MyPID = getpid();
	if (argc != 3)
		perror("ERROR in arguments: \'./client <PID> \"String to send\"\'");
	else
	{
		PID = ft_atoi(argv[1]);
		InitSend(PID, argv[2]);
	}
}
