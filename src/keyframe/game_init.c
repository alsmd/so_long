/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 14:17:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_init(t_game *game)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->map.full_map.img, 0, 0);
	mlx_loop(game->vars.mlx);
}
