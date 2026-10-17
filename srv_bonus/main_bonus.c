/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:41:55 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/28 12:47:32 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

t_stock	g_stock;

int	string_append_char(char c)
{
	char	*tmp;
	size_t	new_cap;

	if (!g_stock.str)
	{
		g_stock.byt_size = 0;
		g_stock.str_cap = 500;
		g_stock.str_size = 0;
		g_stock.str = malloc(g_stock.str_cap);
		if (!g_stock.str)
			return (0);
	}
	if (g_stock.str_size + 1 >= g_stock.str_cap)
	{
		new_cap = g_stock.str_cap * 2;
		tmp = my_realloc(g_stock.str, g_stock.str_cap, new_cap);
		if (!tmp)
			return (0);
		g_stock.str = tmp;
		g_stock.str_cap = new_cap;
	}
	g_stock.str[g_stock.str_size] = c;
	g_stock.str[g_stock.str_size + 1] = '\0';
	g_stock.str_size += 1;
	return (1);
}

static void	add_digit(void)
{
	if (g_stock.current_client == 0)
		g_stock.current_client = g_stock.pid;
	if (g_stock.pid != g_stock.current_client)
		return ;
	if (g_stock.sig == SIGUSR1)
		g_stock.byt[g_stock.byt_size] = '0';
	else if (g_stock.sig == SIGUSR2)
		g_stock.byt[g_stock.byt_size] = '1';
	g_stock.byt_size += 1;
	usleep(200);
	if (kill(g_stock.current_client, SIGUSR1))
	{
		if (g_stock.str)
			free(g_stock.str);
		exit(0);
	}
}

static void	handler0(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_stock.pid = info->si_pid;
	g_stock.sig = sig;
}

static void	byte_to_char(void)
{
	char	c;
	int		i;

	ft_putnbr_fd(g_stock.str_size, 1);
	write(1, "\n", 1);
	g_stock.byt[8] = '\0';
	c = ft_atoi_base(g_stock.byt, "01");
	if (!string_append_char(c))
	{
		if (g_stock.str)
			free(g_stock.str);
		exit(0);
	}
	if (c == 0)
	{
		i = 0;
		while (g_stock.str[i])
			write(1, &(g_stock.str[i++]), 1);
		write(1, "\n", 1);
		free(g_stock.str);
		g_stock.str = NULL;
		g_stock.str_size = 0;
		g_stock.current_client = 0;
	}
	g_stock.byt_size = 0;
}

int	main(void)
{
	struct sigaction	sa;

	g_stock.error = 0;
	g_stock.current_client = 0;
	print_pid();
	sa.sa_sigaction = handler0;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_stock.error)
		{
			if (g_stock.str)
				free(g_stock.str);
			exit(0);
		}
		if (g_stock.pid)
			add_digit();
		if (g_stock.byt_size == 8)
			byte_to_char();
	}
	return (0);
}
