/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:04:32 by flavio            #+#    #+#             */
/*   Updated: 2021/09/18 16:06:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_config(t_game *game)
{
	game->vars.mlx = mlx_init();
	map_config(game);
	player_config(game);
	enemy_config(game);
	if (game->map.w > 14)
		game->width = 14;
	else
		game->width = game->map.w;
	if (game->map.h > 10)
		game->height = 10;
	else
		game->height = game->map.h;
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * BLOCK_SIZE,
			game->height * BLOCK_SIZE, "Dungeon Zone");
}
