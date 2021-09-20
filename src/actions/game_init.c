/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/09/20 11:52:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	frame_update(t_game *game)
{
	static int	screen;
	char		*count;

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
	count = ft_itoa(game->player.steps);
	mlx_string_put(game->vars.mlx, game->vars.win, (game->width * BLOCK_SIZE) - 20\
		, 20, 0xF35C00, count
	);
	free(count);
	return (1);
}

static int	close_game(t_game *game)
{
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	exit(0);
}

static int	key_hook(int keycode, t_game *game)
{
	if (game->game_over || game->win)
		return (1);
	player_action(keycode, game);
	if (keycode == ESC)
		close_game(game);
	return (1);
}

void	game_init(t_game *game)
{
	mlx_loop_hook(game->vars.mlx, frame_update, game);
	mlx_hook(game->vars.win, DestroyNotify, StructureNotifyMask, close_game, game);
	mlx_hook(game->vars.win, KeyPress, KeyPressMask, key_hook, game);
	mlx_loop(game->vars.mlx);
}
