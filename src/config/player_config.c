/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:53 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 09:06:13 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_config(t_game *game)
{
	game->player.w = 48;
	game->player.h = 64;
	player_sprites(game);
}