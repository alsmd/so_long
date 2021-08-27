/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:04:12 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 17:30:38 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_active(t_enemy *enemy)
{
	if (enemy->active < 2)
		enemy->active += 1;
	else
		enemy->active = 0;
}

static void	enemy_animation(t_enemy *enemy)
{
	if (enemy->going_up)
	{
		if (enemy->frame <= 0)
		{
			change_active(enemy);
			enemy->going_up = 0;
		}
		else
			enemy->frame -= .6;
	}
	else
	{
		if (enemy->frame > 7)
			enemy->going_up = 1;
		else
			enemy->frame += .6;
	}
}

int	is_on_map_enemies(t_enemy *enemy, t_game *game)
{
	int	is_on_map;

	is_on_map = 1;
	if (!(enemy->x >= game->map.x && enemy->x < game->map.x + game->width))
		is_on_map = 0;
	if (!(enemy->y >= game->map.y && enemy->y < game->map.y + game->height))
		is_on_map = 0;
	return (is_on_map);
}

void	render_enemies(t_game *game)
{
	t_enemy	*enemy;
	int		x;
	int		y;
	int		i;

	enemy = game->enemies;
	while (enemy)
	{
		if (is_on_map_enemies(enemy, game))
		{
			x = ((enemy->x - game->map.x) * BLOCK_SIZE) + 5;
			y = ((enemy->y - game->map.y) * BLOCK_SIZE) - enemy->frame;
			i = enemy->active;
			copy_img_to(&game->map.map, &enemy->sprites[i],
				to_array(x, y, enemy->sprites[i].w, enemy->sprites[i].h));
			enemy_animation(enemy);
		}
		enemy = enemy->next;
	}
}
