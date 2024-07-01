/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:34:13 by akoutate          #+#    #+#             */
/*   Updated: 2024/07/01 18:31:42 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_ascii(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	digit_checker(char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (count_ascii(str, '.') > 1 || count_ascii(str, '-') > 1)
		return (0);
	else if (count_ascii(str, '-') == 1 && str[0] != '-')
		return (0);
	else if (count_ascii(str, '.') == 1 && str[0] == '.')
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	closer(void)
{
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	(void)data;
	return (0);
}
