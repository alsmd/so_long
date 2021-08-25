/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:04:32 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 13:00:21 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_config(t_game *game)
{
	game->vars.mlx = mlx_init();
	map_config(game);
	if (game->width > 14)
		game->width = 14;
	if (game->height > 10)
		game->height = 10;
	game->vars.win = mlx_new_window(game->vars.mlx, game->width * BLOCK_SIZE,
									game->height * BLOCK_SIZE, "so_long");
	player_config(game);
}