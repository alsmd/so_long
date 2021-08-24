/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:04:32 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 10:06:23 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_config(t_game *game)
{
	game->vars.mlx = mlx_init();
	map_config(game);
	if (game->width > 850)
		game->width = 850;
	if (game->height > 600)
		game->height = 600;
	game->vars.win = mlx_new_window(game->vars.mlx, game->width, game->height, "so_long");
	player_config(game);
}