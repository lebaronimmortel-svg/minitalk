/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:48:08 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/28 17:32:03 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	*my_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = (unsigned char *)src;
	if (d > s && d < s + n)
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

char	*my_realloc(char *s, size_t old_size, size_t new_size)
{
	char	*result;

	result = malloc(new_size);
	if (!result)
		return (NULL);
	if (s)
	{
		if (old_size > new_size)
			old_size = new_size;
		my_memmove(result, s, old_size);
		free(s);
	}
	return (result);
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;	

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + 48;
		write(fd, &c, 1);
	}
	if (n < 10 && n >= 0)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
}
