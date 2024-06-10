/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:34:13 by akoutate          #+#    #+#             */
/*   Updated: 2024/06/10 13:34:41 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	closer(void)
{
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	return (0);
}