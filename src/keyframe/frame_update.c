/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:03 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 19:16:36 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	render_user(t_game *game)
{
	copy_img_to(&game->map.map, &game->player.sprites[0],
				game->player.x * BLOCK_SIZE,
				game->player.y * BLOCK_SIZE, game->player.w,
				game->player.h);
}

int	frame_update(t_game *game)
{
	render_user(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->map.map.img, 0, 0);
}