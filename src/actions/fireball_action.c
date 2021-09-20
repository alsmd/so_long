/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:56:44 by flavio            #+#    #+#             */
/*   Updated: 2021/09/20 11:51:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_fireball(t_fireball *last_one, t_fireball *ball, t_game *game)
{
	if (!last_one)
		game->fireballs = ball->next;
	else
		last_one->next = ball->next;
	free(ball->sprite.img);
	free(ball);
}

static void	draw_fireball(t_fireball *fireball, t_game *game)
{
	int			x;
	int			y;

	x = (fireball->x - game->map.x) * BLOCK_SIZE;
	y = (fireball->y - game->map.y) * BLOCK_SIZE;
	copy_img_to(&game->map.map, &fireball->sprite,
		to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
	check_player_collision(fireball->x, fireball->y, game);
}

void	render_fireball(t_game *game)
{
	t_fireball	*fireball;
	t_fireball	*last_one;

	fireball = game->fireballs;
	last_one = 0;
	while (fireball)
	{
		if (is_on_map(fireball->x, fireball->y, game))
			draw_fireball(fireball, game);
		if (fireball->steps == 8)
		{
			free_fireball(last_one, fireball, game);
			fireball = last_one;
			if (!fireball)
				fireball = game->fireballs;
			if (!fireball)
				break ;
		}
		else
		{
			fireball->x += 1;
			fireball->steps += 1;
		}
		last_one = fireball;
		fireball = fireball->next;
	}
}
