/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:01 by mrubio            #+#    #+#             */
/*   Updated: 2021/09/21 08:55:28 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary(int PID, int b)
{
	if (b == 1)
		kill(PID, SIGUSR1);
	else
		kill(PID, SIGUSR2);
	usleep(100);
}

int	init_send(int PID, const char *str)
{
	int	bit;
	int	x;
	int	bw;

	x = 0;
	while (str[x])
	{
		bw = 7;
		while (bw >= 0)
		{
			bit = (str[x] >> bw) & 0000001;
			send_binary(PID, bit);
			bw--;
		}
		x++;
	}
	bw = 7;
	while (bw >= 0)
	{
		send_binary(PID, 0);
		bw--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*my_pid;
	char	*strpid;
	char	*str;

	if (argc != 3)
		perror("ERROR in arguments: \'./client <Pid> \"String to send\"\'");
	else
	{
		my_pid = ft_itoa(getpid());
		strpid = ft_strjoin(my_pid, " - ");
		free(my_pid);
		str = ft_strjoin(strpid, argv[2]);
		free(strpid);
		pid = ft_atoi(argv[1]);
		init_send(pid, str);
		free(str);
	}
}
