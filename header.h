/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <alexfuen@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:30:55 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/28 17:30:59 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_stock
{
	char	*str;
	size_t	str_size;
	size_t	str_cap;
	char	byt[9];
	int		sig;
	int		pid;
	int		current_client;
	int		byt_size;
}	t_stock;

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi_base(char *str, char *base);
char	*my_realloc(char *s, size_t old_size, size_t new_size);
void	print_pid(void);

#endif
