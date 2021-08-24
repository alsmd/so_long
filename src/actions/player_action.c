/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:32:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 11:16:15 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_action(int keycode, t_game *game)
{
	int	vel;

	vel = 1;
	if (keycode == W)
	{
		game->player.frame = 0;
		game->player.y -= vel;
	}
	if (keycode == A)
	{
		game->player.frame = 3;
		game->player.x -= vel;

	}
	if (keycode == S)
	{
		game->player.frame = 2;
		game->player.y += vel;
	}
	if (keycode == D)
	{
		game->player.frame = 1;
		game->player.x += vel;
	}
}