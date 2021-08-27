/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 20:39:33 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_over(t_game *game)
{
	int				x;
	int				y;
	static int		going_up;
	static float	d;

	t_data	game_over;
	game_over.w = 544;
	game_over.h = 416;
	load_img(&game_over, "./imgs/over.xpm", game);
	x = (game->width * BLOCK_SIZE) - game_over.w;
	if (x < 0)
		x = 0;
	y = (game->height * BLOCK_SIZE) - game_over.h;
	if (y < 0)
		y = 0;
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game_over.img, x, y + d);
	if (going_up)
	{
		if (d > 0)
			d -= 0.5;
		else
			going_up = 0;

	}
	else
	{
		if (d < 18)
			d += 0.5;
		else
			going_up = 1;
	}
	free(game_over.img);
}
int	frame_update(t_game *game)
{
	if (game->game_over)
	{
		print_over(game);
		return (1);
	}
	get_active_map(game);
	render_user(game);
	render_enemies(game);
	render_items(game);
	render_fireball(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->map.map.img, 0, 0);
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (game->game_over)
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
