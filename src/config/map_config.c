/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:15:44 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 14:18:37 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	get_tile(char c, t_data *tile, t_game *game)
{
	char	*path;
	int		size;

	size = BLOCK_SIZE;
	if (c == '0')
		path = "./imgs/floor.xpm";
	if (c == '1')
		path = "./imgs/wall.xpm";
	if (c == 'E')
		path = "./imgs/gate.xpm";
	if (c == 'P')
		path = "./imgs/player.xpm";
	if (c == 'C')
		path = "./imgs/item.xpm";
	tile->img = mlx_xpm_file_to_image(game->vars.mlx, path, &size, &size);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
				&tile->line_length, &tile->endin);
}

void	map_config(t_game *game)
{
	int		x;
	int		x_holder;
	t_data	tile;
	int		y;

	x = game->width / BLOCK_SIZE;
	x_holder = x;
	y = game->height / BLOCK_SIZE;
	game->map.full_map.img = mlx_new_image(game->vars.mlx, game->width, game->height);
	game->map.full_map.addr = mlx_get_data_addr(game->map.full_map.img,
				&game->map.full_map.bits_per_pixel,
				&game->map.full_map.line_length, &game->map.full_map.endin);
	while (y--)
	{
		while (x--)
		{
			get_tile(game->map.layout[y][x], &tile, game);
			copy_img_to(&game->map.full_map, &tile, x * BLOCK_SIZE,
					y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
		}
		x = x_holder;
	}
}