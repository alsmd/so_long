/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:03 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 11:13:46 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	render_user(t_game *game)
{
	copy_img_to(&game->map.map, &game->player.sprites[game->player.frame],
				game->player.x * BLOCK_SIZE,
				game->player.y * BLOCK_SIZE, game->player.w,
				game->player.h);
}

void	render_items(t_game *game)
{
	t_item	*begin;
	int		is_on_map;


	begin = game->items;
	while (begin)
	{
		is_on_map = ((game->map.x + begin->x) * BLOCK_SIZE) < game->width;
		is_on_map = is_on_map && \
				((game->map.y + begin->y) * BLOCK_SIZE) < game->height;
		if (is_on_map)
		{
			copy_img_to(&game->map.map, &begin->sprites[0],
				(begin->x - game->map.x) * BLOCK_SIZE,
				(begin->y - game->map.y) * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
		}
		begin = begin->next;
	}
}
int	frame_update(t_game *game)
{
	get_active_map(game);
	render_user(game);
	render_items(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->map.map.img, 0, 0);
	return (1);
}