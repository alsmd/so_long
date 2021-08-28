/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:32:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 15:00:27 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_action(int keycode, t_game *game)
{
	if (keycode == W)
		up(game);
	if (keycode == A)
		left(game);
	if (keycode == S)
		down(game);
	if (keycode == D)
		right(game);
}

void	render_user(t_game *game)
{	
	t_data	*sprite;
	int		x;
	int		y;

	x = game->player.x * BLOCK_SIZE;
	y = game->player.y * BLOCK_SIZE;
	sprite = &game->player.sprites[game->player.frame];
	copy_img_to(&game->map.map, sprite,
		to_array(x, y, game->player.w, game->player.h));
}

void	check_player_collision(int x, int y, t_game *game)
{
	if ((game->player.x + game->map.x) == x && \
		(game->player.y + game->map.y) == y)
		game->game_over = 1;
}
