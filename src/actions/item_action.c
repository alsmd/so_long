/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 11:59:37 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 14:36:20 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	item_animation(t_item *item)
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

int	is_on_map(t_item *item, t_game *game)
{
	int	is_on_map;

	is_on_map = 1;
	if (!(item->x >= game->map.x && item->x < game->map.x + game->width))
		is_on_map = 0;
	if (!(item->y >= game->map.y && item->y < game->map.y + game->height))
		is_on_map = 0;
}

void	render_items(t_game *game)
{
	t_item	*item;
	int		x;
	int		y;

	item = game->items;
	while (item)
	{
		if (is_on_map(item, game))
		{
			x = (item->x - game->map.x) * BLOCK_SIZE;
			y = (item->y - game->map.y) * BLOCK_SIZE;
			copy_img_to(&game->map.map, &item->sprite,
				to_array(x, y + item->frame, BLOCK_SIZE, BLOCK_SIZE));
			item_animation(item);
		}
		item = item->next;
	}
}
