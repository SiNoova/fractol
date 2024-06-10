/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:56:11 by akoutate          #+#    #+#             */
/*   Updated: 2024/06/10 13:35:18 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

typedef struct complex
{
	double	real;
	double	imag;
}	t_comp;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		j;
	t_comp	*c;
	t_comp	*z;
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
	char	*set;
	double	imag;
	double	real;
}	t_data;

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_image(t_comp c, t_comp z, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
double	my_atoi(char *str);
int		ft_strlen(char *str);
int		closer(void);
int		key_hook(int keycode, t_data *data);

#endif