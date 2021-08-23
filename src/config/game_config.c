/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:04:32 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 14:16:53 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_config(t_game *game)
{
	if (game->width > 850)
		game->width = 850;
	if (game->height > 600)
		game->height = 600;
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->width, game->height, "so_long");
	map_config(game);
}