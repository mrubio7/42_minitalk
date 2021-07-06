/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:01 by mrubio            #+#    #+#             */
/*   Updated: 2021/07/06 12:35:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(const char *str)
{
	int				x;
	long long int	num;
	long long int	sig;

	x = 0;
	sig = 1;
	num = 0;
	while (str[x] == 32 || str[x] == 10 || str[x] == 9
		|| str[x] == 12 || str[x] == 13 || str[x] == 11)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sig = -1;
		x++;
	}
	while (str[x] != '\0')
	{
		if (str[x] < 48 || 57 < str[x])
			return (num * sig);
		else
			num = (num * 10) + (str[x] - '0');
		x++;
	}
	return (num * sig);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		printf("ERROR in arguments: \'./send <Num. PID> <\"String to send\">\'");
	else
	{
		int PID;

		PID = ft_atoi(argv[1]);
		kill(PID, SIGUSR1);
	}
}