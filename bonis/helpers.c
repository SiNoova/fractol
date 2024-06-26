/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:33:25 by akoutate          #+#    #+#             */
/*   Updated: 2024/05/06 05:40:41 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_swap(double *a, double *b, double *c, double *d)
{
	double	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	coloring(t_data *data)
{
	int		i;
	int		k;
	int 	j;
	double	tmp;

	i = -1;
	k = 25;
	j = 25;
	while (++i < 500)
	{
		tmp = data->z->real;
		data->z->real = data->c->real + (data->z->real * data->z->real)
			- (data->z->imag * data->z->imag);
		data->z->imag = data->c->imag + 2 * tmp * data->z->imag;
		if (data->z->real * data->z->real
			+ data->z->imag * data->z->imag > 4)
		{
			my_mlx_pixel_put(data, data->x, data->y, create_trgb(0, j, k, j));
			data->j = 0;
			break ;
		}
		if (k < 255)
			k += 5;
		else
		{
			k = 25;
			j += 10;
		}
	}
	if (data->j)
		my_mlx_pixel_put(data, data->x, data->y, 0x000000);

}

void	fill_image(t_comp c, t_comp z, t_data *data)
{
	int		x;
	int		y;
	int		j;

	y = 0;
	j = 1;
	while (y < 800)
	{
		x = 0;
		data->y = y;
		while (x < 800)
		{
			j = 1;
			c.imag = ((double)y / (800 / (data->y_end - data->y_start))) + data->y_start;
			c.real = ((double)x / (800 / (data->x_end - data->x_start))) + data->x_start;
			z.real = data->real;
			z.imag = data->imag;
			if (ft_strlen(data->set) == 1 && *(data->set) == 'j')
				ft_swap(&c.real, &z.real, &c.imag, &z.imag);
			data->x = x++;
			data->j = j;
			data->c = &c;
			data->z = &z;
			coloring(data);
		}
		y++;
	}
}
