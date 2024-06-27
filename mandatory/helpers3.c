/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:34:13 by akoutate          #+#    #+#             */
/*   Updated: 2024/06/27 17:18:14 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	digit_checker(char *str)
{
	int	i;

	i = 0;
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
