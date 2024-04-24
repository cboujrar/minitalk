/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:12:29 by cboujrar          #+#    #+#             */
/*   Updated: 2024/04/21 16:16:55 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert_dec(char *s)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 1;
	while (i <= 7)
	{
		if (s[i] == '1')
			a = a + b;
		b = b * 2;
		i++;
	}
	return (a);
}

void	handle_sigusr(int sign)
{
	char		str[8];
	static int	bit;
	int			a;

	a = 0;
	if (sign == SIGUSR1)
	{
		str[bit] = '0';
		bit++;
	}
	else if (sign == SIGUSR2)
	{
		str[bit] = '1';
		bit++;
	}
	if (bit == 8)
	{
		a = convert_dec(str);
		write(1, &a, 1);
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("the pid is :%d\n", pid);
	if (signal(SIGUSR1, &handle_sigusr) == SIG_ERR)
		ft_printf("error\n");
	else if (signal(SIGUSR2, &handle_sigusr) == SIG_ERR)
		ft_printf("error\n");
	while (1)
	{
		pause();
	}
	return (0);
}
