/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:05:35 by alexfuen          #+#    #+#             */
/*   Updated: 2026/01/28 17:31:34 by alexfuen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	check_base(char *base, int len_base)
{
	int	j;
	int	a;

	j = 0;
	while (j < len_base)
	{
		if (base[j] == '+' || base[j] == '-' || base[j] == ' ')
			return (0);
		if (base[j] >= 9 && base[j] <= 13)
			return (0);
		a = j + 1;
		while (a < len_base)
		{
			if (base[j] == base[a])
				return (0);
			a++;
		}
		j++;
	}
	return (1);
}

static int	check_space(char *str, int i)
{
	if (str[i] < 9 || (str[i] > 13 && str[i] != ' '))
		return (0);
	return (1);
}

static int	convert(char *str, int i, char *base, int len_base)
{
	int	iter;
	int	result;

	result = 0;
	while (str[i])
	{
		iter = 0;
		while (base[iter])
		{
			if (str[i] == base[iter])
			{
				result = result * len_base + iter;
				break ;
			}
			iter++;
		}
		if (str[i] != base[iter])
			return (result);
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	i;
	int	signe;
	int	len_base;

	len_base = ft_strlen(base);
	if (check_base(base, len_base) == 0)
		return (0);
	i = 0;
	result = 0;
	signe = 1;
	while (check_space(str, i))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	result = convert(str, i, base, len_base);
	return (result * signe);
}
