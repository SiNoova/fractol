/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:32:42 by akoutate          #+#    #+#             */
/*   Updated: 2024/05/04 18:59:52 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int closer()
{
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	t_comp		comp;
	t_comp		z_comp;
	float		tmp;
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
	{
		tmp = data->x_start;
		data->x_start += 0.2 / 4 * (-data->x_start + data->x_end);
		data->x_end += 0.2 / 4 * (-tmp + data->x_end);
	}
	else if (keycode == 126)
	{
		tmp = data->y_start;
		data->y_start += 0.2 / 4 * (data->y_start - data->y_end);
		data->y_end += 0.2 / 4 * (tmp - data->y_end);
	}
	else if (keycode == 125)
	{
		tmp = data->y_start;
		data->y_start -= 0.2 / 4 * (data->y_start - data->y_end);
		data->y_end -= 0.2 / 4 * (tmp - data->y_end);
	}
	else if (keycode == 123)
	{
		tmp = data->x_start;
		data->x_start -= 0.2 / 4 * (-data->x_start + data->x_end);
		data->x_end -= 0.2 / 4 * (-tmp + data->x_end);
	}
	fill_image(comp, z_comp, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode,int x, int y ,t_data *data)
{
	t_comp		comp;
	t_comp		z_comp;
	float		tmp;

	if (mousecode == 4)
	{
		tmp = data->x_start;
		data->x_start += 0.5 / 4 * (-data->x_start + data->x_end);
		data->x_end -= 0.5 / 4 * (-tmp + data->x_end);
		tmp = data->y_start;
		data->y_start -= 0.5 / 4 * (data->y_start - data->y_end);
		data->y_end += 0.5 / 4 * (tmp - data->y_end);
	}
	else if (mousecode == 5)
	{
		tmp = data->x_start;
		data->x_start -= 0.5 / 4 * (-data->x_start + data->x_end);
		data->x_end += 0.5 / 4 * (-tmp + data->x_end);
		tmp = data->y_start;
		data->y_start += 0.5 / 4 * (data->y_start - data->y_end);
		data->y_end -= 0.5 / 4 * (tmp - data->y_end);
	}
	fill_image(comp, z_comp, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_comp		comp;
	t_comp		z_comp;

	data.x_start = -2;
	data.x_end = 2;
	data.y_start = 2;
	data.y_end = -2;
	data.real = 0;
	data.imag = 0;
	data.set = av[1];
	if (ac == 4 && av[1][0] == 'j')
	{
		data.real = atof(av[2]);
		data.imag = atof(av[3]);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "mandelbrot");
	data.img = mlx_new_image(data.mlx, 800, 800);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	fill_image(comp, z_comp, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0, closer , NULL);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
