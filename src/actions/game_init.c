/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 14:58:34 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	frame_update(t_game *game)
{
	static int screen;

	if (game->game_over)
	{
		if (!screen)
			print_over(game);
		screen = 1;
		return (1);
	}
	if (game->win)
	{
		if (!screen)
			print_screen(game);
		screen = 1;
		return (1);
	}
	get_active_map(game);
	render_user(game);
	render_enemies(game);
	render_items(game);
	render_fireball(game);
	check_exit(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->map.map.img, 0, 0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (game->game_over || game->win)
		return (1);
	player_action(keycode, game);
	return (1);
}

void	game_init(t_game *game)
{
	mlx_loop_hook(game->vars.mlx, frame_update, game);
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, key_hook, game);
	mlx_loop(game->vars.mlx);
}
