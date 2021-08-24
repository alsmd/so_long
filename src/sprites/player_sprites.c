/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:01:21 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 09:05:56 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_sprites(t_game *game)
{	
	t_data	full_sprite;
	int		w;
	int		h;

	w = 144;
	h = 256;
	full_sprite.img = mlx_xpm_file_to_image(game->vars.mlx, "./imgs/male.xpm", &w, &h);
	full_sprite.addr = mlx_get_data_addr(full_sprite.img,
						&full_sprite.bits_per_pixel, &full_sprite.line_length,
						&full_sprite.endin);
	game->player.sprites[0].img = mlx_new_image(game->vars.mlx, game->player.w,
								game->player.h);
	game->player.sprites[0].addr = mlx_get_data_addr(game->player.sprites[0].img,
						&game->player.sprites[0].bits_per_pixel,
						&game->player.sprites[0].line_length,
						&game->player.sprites[0].endin);
	copy_img_from(&game->player.sprites[0], &full_sprite, 0,
					game->player.h * 2, game->player.w,
					game->player.h);
}