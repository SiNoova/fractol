/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:32:42 by akoutate          #+#    #+#             */
/*   Updated: 2024/06/27 17:22:15 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setting_up_data(t_data *data)
{
	data->x_start = -2;
	data->x_end = 2;
	data->y_start = 2;
	data->y_end = -2;
	data->real = 0;
	data->imag = 0;
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	t_comp		comp;
	t_comp		z_comp;

	if (mousecode == 4)
	{
		data->x_start /= 1.3;
		data->x_end /= 1.3;
		data->y_start /= 1.3;
		data->y_end /= 1.3;
	}
	else if (mousecode == 5)
	{
		data->x_start = data->x_start * 1.3;
		data->x_end *= 1.3;
		data->y_start *= 1.3;
		data->y_end *= 1.3;
	}
	fill_image(&comp, &z_comp, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	x = 0;
	y = 0;
	return (0);
}

void	starting_mlx(t_data *data, t_comp *comp, t_comp *z_comp)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "fractol");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	fill_image(comp, z_comp, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, closer, NULL);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_comp		comp;
	t_comp		z_comp;

	setting_up_data(&data);
	if (ac == 4 && av[1][0] == 'j' && ft_strlen(av[1]) == 1
		&& digit_checker(av[2]) && digit_checker(av[3]))
	{
		data.real = atof(av[2]);
		data.imag = atof(av[3]);
		data.set = av[1];
	}
	else if (ac == 2 && av[1][0] == 'm')
		data.set = av[1];
	else
	{
		write(1, "invalid syntax:\n./a.out m (for mandelbrot)\n", 44);
		write(1, "./a.out j x y (for julia sets)\n", 32);
		return (0);
	}
	starting_mlx(&data, &comp, &z_comp);
}
