/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:03 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 10:06:30 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	render_user(t_game *game)
{
	copy_img_to(&game->map.full_map, &game->player.sprites[0],
				game->player.x * BLOCK_SIZE,
				game->player.y * BLOCK_SIZE, game->player.w,
				game->player.h);
}

void	render_items(t_game *game)
{
	t_item	*begin;

	begin = game->items;
	while (begin)
	{
		copy_img_to(&game->map.full_map, &begin->sprites[0],
				begin->x * BLOCK_SIZE,
				begin->y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
		begin = begin->next;
	}
}
int	frame_update(t_game *game)
{
	render_user(game);
	render_items(game);
	get_active_map(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->map.map.img, 0, 0);
}