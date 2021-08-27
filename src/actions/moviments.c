/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:46:33 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 12:52:41 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	up(t_game *game)
{
	if (check_mov(game, 0, -1))
	{
		if (game->map.y > 0 && game->player.y < (game->height) / 2)
			game->map.y -= 1;
		else
			game->player.y -= 1;
	}
	game->player.frame = 0;
}

void	down(t_game *game)
{
	if (check_mov(game, 0, 1))
	{
		if (game->map.y < game->map.h - game->height \
			&& game->player.y > game->height / 2)
			game->map.y += 1;
		else
			game->player.y += 1;
	}
	game->player.frame = 2;
}

void	left(t_game *game)
{
	if (check_mov(game, -1, 0))
		{
			if (game->map.x > 0  && game->player.x < (game->width) / 2)
				game->map.x -= 1;
			else
				game->player.x -= 1;
		}
		game->player.frame = 3;
}

void	right(t_game *game)
{
	if (check_mov(game, 1, 0))
	{
		if ((game->map.x < game->map.w - game->width)\
			&& game->player.x > game->width / 2
		)
			game->map.x += 1;
		else
			game->player.x += 1;
	}
	game->player.frame = 1;
}