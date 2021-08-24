/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:17:03 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 11:36:54 by flavio           ###   ########.fr       */
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

void	key_animation(t_item *item)
{
	if (item->going_up)
	{
		if (item->frame <= 0)
			item->going_up = 0;
		else
			item->frame -= .6;
	}
	else
	{
		if (item->frame > 7)
			item->going_up = 1;
		else
			item->frame += .6;
	}
}

void	render_items(t_game *game)
{
	t_item	*item;
	int		is_on_map;


	item = game->items;
	while (item)
	{
		is_on_map = ((game->map.x + item->x) * BLOCK_SIZE) < game->width;
		is_on_map = is_on_map && \
				((game->map.y + item->y) * BLOCK_SIZE) < game->height;
		if (is_on_map)
		{
			copy_img_to(&game->map.map, &item->sprites[0],
				(item->x - game->map.x) * BLOCK_SIZE,
				(item->y - game->map.y) * BLOCK_SIZE + item->frame, BLOCK_SIZE, BLOCK_SIZE);
			key_animation(item);

		}
		item = item->next;
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