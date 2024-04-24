/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboujrar <cboujrar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:25:31 by cboujrar          #+#    #+#             */
/*   Updated: 2024/04/24 13:51:12 by cboujrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int	is_number(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	len;

	len = count * size;
	if (count != 0 && len / count != size)
		return (NULL);
	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

int	ft_atoi(const char *str)
{
	long long result;
	int	signe;

	result = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (signe == 1 && result > 2147483647)
		exit(1);
	else if (signe == -1 && - result < -2147483648)
		exit(1);
	return (result * signe);
}
