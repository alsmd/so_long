/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 13:01:12 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 13:51:43 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_open_exit(int x, int y, t_game *game)
{
	t_data	img;

	img.w = BLOCK_SIZE;
	img.h = BLOCK_SIZE;
	x *= BLOCK_SIZE;
	y *= BLOCK_SIZE;
	load_img(&img, "./imgs/exit2.xpm", game);
	copy_img_to(&game->map.full_map, &img,
		to_array(x, y, img.w, img.h));
	free(img.img);
}

static void	open_exits(t_game *game)
{
	int			x;
	int			x_holder;
	int			y;

	x = game->map.w;
	x_holder = x;
	y = game->map.h;
	while (y--)
	{
		while (x--)
		{
			if (game->map.layout[y][x] == 'E')
				draw_open_exit(x, y, game);
		}
		x = x_holder;
	}
}

void	check_exit(t_game *game)
{
	static int	open;
	int			x;
	int			y;

	if (!game->items && !open)
	{
		open = 1;
		open_exits(game);
	}
	if (!game->items)
	{
		x = game->player.x + game->map.x;
		y = game->player.y + game->map.y;
		if (game->map.layout[y][x] == 'E')
			game->win = 1;
	}
}
