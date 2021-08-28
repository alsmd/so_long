/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 09:51:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 13:00:56 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_over_animation(int *going_up, float *frame)
{
	if (*going_up)
	{
		if (*frame > 0)
			*frame -= 0.5;
		else
			*going_up = 0;
	}
	else
	{
		if (*frame < 18)
			*frame += 0.5;
		else
			*going_up = 1;
	}
}

void	print_over(t_game *game)
{
	t_data			game_over;
	int				x;
	int				y;
	static int		going_up;
	static float	frame;

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
		game_over.img, x, y + frame);
	game_over_animation(&going_up, &frame);
	free(game_over.img);
}
