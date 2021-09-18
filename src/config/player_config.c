/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:53 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 14:29:18 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_config(t_game *game)
{
	t_data		full_sprite;
	t_player	*player;
	int			i;

	i = 0;
	player = &game->player;
	player->steps = 0;
	full_sprite.w = 144;
	full_sprite.h = 256;
	player->w = 48;
	player->h = 64;
	player->frame = 2;
	load_img(&full_sprite, "./imgs/male.xpm", game);
	while (i < 4)
	{
		create_img(&player->sprites[i], player->w, player->h, game);
		copy_img_from(&player->sprites[i], &full_sprite,
			to_array(0, player->h * i, player->w, player->h));
		i++;
	}
}
