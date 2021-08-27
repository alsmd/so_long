/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 16:28:58 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

	enemy = game->enemies;
	while (enemy)
	{
		if (is_on_map_enemies(enemy, game))
		{
			x = (enemy->x - game->map.x) * BLOCK_SIZE;
			y = (enemy->y - game->map.y) * BLOCK_SIZE;
			copy_img_to(&game->map.map, &enemy->sprites[0],
				to_array(x, y, enemy->sprites[0].w, enemy->sprites[0].h));
		}
		enemy = enemy->next;
	}
}

int	frame_update(t_game *game)
{
	get_active_map(game);
	render_user(game);
	render_items(game);
	render_enemies(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->map.map.img, 0, 0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	player_action(keycode, game);
	return (1);
}

void	game_init(t_game *game)
{
	mlx_loop_hook(game->vars.mlx, frame_update, game);
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, key_hook, game);
	mlx_loop(game->vars.mlx);
}
