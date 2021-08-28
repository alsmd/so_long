/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:56:44 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 12:20:33 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_on_map_fireball(t_fireball *ball, t_game *game)
{
	int	is_on_map;

	is_on_map = 1;
	if (!(ball->x >= game->map.x && ball->x < game->map.x + game->width))
		is_on_map = 0;
	if (!(ball->y >= game->map.y && ball->y < game->map.y + game->height))
		is_on_map = 0;
	return (is_on_map);
}

void	free_fireball(t_fireball *last_one, t_fireball *ball, t_game *game)
{
	if (!last_one)
		game->fireballs = 0;
	else
		last_one->next = ball->next;
	free(ball->sprite.img);
	free(ball);
}

void	draw_fireball(t_fireball *fireball, t_game *game)
{
	int			x;
	int			y;

	x = (fireball->x - game->map.x) * BLOCK_SIZE;
	y = (fireball->y - game->map.y) * BLOCK_SIZE;
	copy_img_to(&game->map.map, &fireball->sprite,
		to_array(x, y, BLOCK_SIZE, BLOCK_SIZE));
}

void	render_fireball(t_game *game)
{
	t_fireball	*fireball;
	t_fireball	*last_one;

	fireball = game->fireballs;
	last_one = 0;
	while (fireball)
	{
		if (is_on_map_fireball(fireball, game))
			draw_fireball(fireball, game);
		if (fireball->steps == 10)
		{
			free_fireball(last_one, fireball, game);
			fireball = last_one;
			if (!fireball)
				break ;
		}
		else
		{
			fireball->x += 1;
			fireball->steps += 1;
		}
		check_player_collision(fireball->x, fireball->y, game);
		last_one = fireball;
		fireball = fireball->next;
	}
}
