/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:23:01 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 13:53:08 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_mov(t_game *game, int x, int y)
{
	y += game->player.y + game->map.y;
	x += game->player.x + game->map.x;
	if (game->map.layout[y][x] != '1')
		return (1);
	return (0);
}
