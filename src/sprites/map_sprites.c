/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:36:24 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 09:08:24 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


static void	get_tile(char c, t_data *tile, t_game *game)
{
	char	*path;
	int		size;

	size = BLOCK_SIZE;
	if (c == '0')
		path = "./imgs/floor1.xpm";
	if (c == '1')
		path = "./imgs/wall1.xpm";
	if (c == 'E')
		path = "./imgs/gate.xpm";
	if (c == 'P')
		path = "./imgs/floor1.xpm";
	if (c == 'C')
		path = "./imgs/item.xpm";
	tile->img = mlx_xpm_file_to_image(game->vars.mlx, path, &size, &size);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
				&tile->line_length, &tile->endin);
}

void	get_active_map(t_game *game)
{
	game->map.map.img = mlx_new_image(game->vars.mlx, game->width, game->height);
	game->map.map.addr = mlx_get_data_addr(game->map.map.img,
						&game->map.map.bits_per_pixel,
						&game->map.map.line_length, &game->map.map.endin);
	copy_img_from(&game->map.map, &game->map.full_map, game->map.x, game->map.y,
				game->width, game->height);
}

void	map_sprites(t_game *game)
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
			if (game->map.layout[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			get_tile(game->map.layout[y][x], &tile, game);
			copy_img_to(&game->map.full_map, &tile, x * BLOCK_SIZE,
					y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
		}
		x = x_holder;
	}
}