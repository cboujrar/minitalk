/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:16:16 by cboujrar          #+#    #+#             */
/*   Updated: 2024/04/24 13:49:49 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*convert_bit(int a)
{
	int	i;
	int	*str;

	i = 0;
	str = ft_calloc(8, sizeof(int));
	while (i <= 7)
	{
		str[i] = a % 2;
		a = a / 2;
		i++;
	}
	return (str);
}

void	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_number(str[i]) == 0 || str[0] == '0')
		{
			ft_printf("invalid server ID\n");
			exit(1);
		}
		i++;
	}
}

void	send_bit(int *b, int pid)
{
	int	j;

	j = 0;
	while (j <= 7)
	{
		if (b[j] == 0)
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("ERROR");
				exit(1);
			}
		}
		else if (b[j] == 1)
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_printf("ERROR");
				exit(1);
			}
		}
		j++;
		usleep(500);
	}
}

void	send_message(char *message, int pid)
{
	int	i;
	int	j;
	int	*b;

	i = 0;
	j = 0;
	while (message[i])
	{
		b = convert_bit(message[i]);
		j = 0;
		send_bit(b, pid);
		i++;
		free(b);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		check_pid(av[1]);
		pid = ft_atoi(av[1]);
		send_message(av[2], pid);
	}
	else
		ft_printf("you should write one message!\n");
	return (0);
}
