/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:15:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 19:09:11 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

int	my_mlx_get_pixel(t_data *data, int x, int y)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dest);
}

void	copy_img_from(t_data *dest, t_data *src, int x_src, int y_src, int width, int height)
{
	int	pixel;
	int	x;
	int	y;
	int	holder;

	x = 0;
	y = 0;
	holder = y_src;
	while (x < width)
	{
		while (y < height)
		{
			pixel = my_mlx_get_pixel(src, x_src, y_src);
			if (pixel != 0  && pixel != -16777216)
				my_mlx_pixel_put(dest, x, y, pixel);
			y++;
			y_src++;
		}
		y = 0;
		y_src = holder;
		x_src++;
		x++;
	}
}

void	copy_img_to(t_data *dest, t_data *src, int x_dest, int y_dest, int width, int height)
{
	int	pixel;
	int	x;
	int	y;
	int	holder;

	x = 0;
	y = 0;
	holder = y_dest;
	while (x < width)
	{
		while (y < height)
		{
			pixel = my_mlx_get_pixel(src, x, y);
			if (pixel != 0  && pixel != -16777216)
				my_mlx_pixel_put(dest, x_dest, y_dest, pixel);
			y++;
			y_dest++;
		}
		y = 0;
		y_dest = holder;
		x_dest++;
		x++;
	}
}

void	clear_image(t_data *img, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;	
	while (x < width)
	{
		while (y < height)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}
