/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:10:41 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 18:17:59 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	game_init(t_game *game)
{
	mlx_loop_hook(game->vars.mlx, frame_update, game);
	mlx_loop(game->vars.mlx);
}
