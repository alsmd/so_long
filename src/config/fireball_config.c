/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:57:37 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 19:37:24 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	new_fireball(t_game *game, int x, int y)
{
	t_fireball	*begin;
	t_fireball	*new_item;

	new_item = (t_fireball *) ft_calloc(1, sizeof(t_fireball));
	new_item->x = x;
	new_item->y = y;
	new_item->sprite.w = 64;
	new_item->sprite.h = 64;
	load_img(&new_item->sprite, "./imgs/fireball/1.xpm", game);
	begin = game->fireballs;
	while (begin && begin->next)
		begin = begin->next;
	if (begin)
		begin->next = new_item;
	else
		game->fireballs = new_item;
}
