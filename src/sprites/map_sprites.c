/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavi	o@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:36:24 by flavio            #+#    #+#             */
/*   Updated: 2021/08/26 15:57:51 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


static void	get_tile(char c, t_data *tile, t_game *game)
{
	char			*path;
	static size_t	i;
	int				size;

	size = BLOCK_SIZE;
	if (c == '1')
		path = "./imgs/wall3.xpm";
	if (c == 'E')
		path = "./imgs/portal2.xpm";
	if (c == 'C' || c == 'P' || c == '0')
	{
		if (i % 18 == 0)
			path = "./imgs/floor4.xpm";
		else if (i % 28 == 0)
			path = "./imgs/floor5.xpm";
		else
			path = "./imgs/floor3.xpm";
		i++;
	}
	tile->img = mlx_xpm_file_to_image(game->vars.mlx, path, &size, &size);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
				&tile->line_length, &tile->endin);
}

void	get_active_map(t_game *game)
{
	if (!game->map.map.img)
	{
		game->map.map.img = mlx_new_image(game->vars.mlx, game->width * BLOCK_SIZE,
						game->height * BLOCK_SIZE);
		game->map.map.addr = mlx_get_data_addr(game->map.map.img,
						&game->map.map.bits_per_pixel,
						&game->map.map.line_length, &game->map.map.endin);
	}
	copy_img_from(&game->map.map, &game->map.full_map, game->map.x * BLOCK_SIZE
					, game->map.y * BLOCK_SIZE,
					game->width * BLOCK_SIZE, game->height * BLOCK_SIZE);
}

void	map_sprites(t_game *game)
{
	int		x;
	int		x_holder;
	t_data	tile;
	int		y;


	x = game->map.w;
	x_holder = x;
	y = game->map.h;
	game->map.full_map.img = mlx_new_image(game->vars.mlx, x * BLOCK_SIZE,
							y * BLOCK_SIZE);
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
			if (game->map.layout[y][x] == 'C')
				new_item(game, x, y);
			if (game->map.layout[y][x] == 'E')
			{
				get_tile('0', &tile, game);
				copy_img_to(&game->map.full_map, &tile, x * BLOCK_SIZE,
					y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
			}
			get_tile(game->map.layout[y][x], &tile, game);
			copy_img_to(&game->map.full_map, &tile, x * BLOCK_SIZE,
					y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
		}
		x = x_holder;
	}
	
}