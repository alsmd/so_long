/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:15:44 by flavio            #+#    #+#             */
/*   Updated: 2021/08/25 17:58:22 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_config(t_game *game)
{
	game->map.x = 0;
	game->map.y = 0;
	game->map.map.img = 0;
	map_sprites(game);
}