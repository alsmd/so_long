/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:32:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/26 17:42:46 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player(t_game *game, int x, int y)
{
	
}

void	player_action(int keycode, t_game *game)
{
	int	vel;

	vel = 1;
	if (keycode == W)
	{
		if (check_mov(game, 0, -1))
		{
			if (game->map.y > 0 && game->player.y < (game->height) / 2)
				game->map.y -= vel;
			else
				game->player.y -= vel;
		}
		game->player.frame = 0;
	}
	if (keycode == A)
	{
		if (check_mov(game, -1, 0))
		{
			if (game->map.x > 0  && game->player.x < (game->width) / 2)
				game->map.x -= vel;
			else
				game->player.x -= vel;
		}
		game->player.frame = 3;

	}
	if (keycode == S)
	{
		if (check_mov(game, 0, 1))
		{
			if (game->map.y < game->map.h - game->height \
				&& game->player.y > game->height / 2)
				game->map.y += vel;
			else
				game->player.y += vel;
		}
		game->player.frame = 2;
	}
	if (keycode == D)
	{
		if (check_mov(game, 1, 0))
		{
			if ((game->map.x < game->map.w - game->width)\
				&& game->player.x > game->width / 2
			)
				game->map.x += vel;
			else
				game->player.x += vel;
		}
		game->player.frame = 1;
	}
}