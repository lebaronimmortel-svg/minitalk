/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:37:11 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/28 12:47:15 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	g_ack;

static int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	while ((nptr[i] < 14 && nptr[i] > 8) || nptr[i] == 32)
		i++;
	sign = 1;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (sign * result);
}

static void	stock_bits(unsigned int byte, char *buffer)
{
	int	i;
	int	j;

	j = 0;
	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
		{
			buffer[j] = '1';
			j++;
		}
		else
		{
			buffer[j] = '0';
			j++;
		}
		i--;
	}
}

static void	send(char c, int pid)
{
	if (c == '0')
	{
		if (kill(pid, SIGUSR1))
			exit(0);
	}
	else if (c == '1')
	{
		if (kill(pid, SIGUSR2))
			exit(0);
	}
	g_ack = 0;
	while (g_ack == 0)
		pause();
	usleep(100);
}

static void	handler(int sig)
{
	(void) sig;
	g_ack = 1;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	str[8];
	int		len;
	int		i;
	int		j;

	if (argc != 3)
		return (-1);
	signal(SIGUSR1, handler);
	len = 0;
	while (argv[2][len])
		len++;
	pid = ft_atoi(argv[1]);
	j = 0;
	while (j <= len)
	{
		stock_bits(argv[2][j], str);
		i = 0;
		while (i < 8)
			send(str[i++], pid);
		j++;
	}
	return (0);
}
