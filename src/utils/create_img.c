/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:31:10 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 11:08:02 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_img(t_data *img, char *path, t_game *game)
{
	img->img = mlx_xpm_file_to_image(game->vars.mlx, path, &img->w, &img->h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endin);
}

void	create_img(t_data *img, int w, int h, t_game *game)
{
	img->img = mlx_new_image(game->vars.mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_length, &img->endin);
}