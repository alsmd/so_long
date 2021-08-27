/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:16:13 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 16:41:15 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_surround(int y, int x, t_game *game)
{
	char	**layout;
	int		range;
	int		index;

	index = 0;
	range = 5;
	layout = game->map.layout;
	if (layout[y][x] == '1')
		return (0);
	if (layout[y][x + 1] == 'E')
		return (1);
	if (layout[y][x - 1] == 'E')
		return (1);
	if (layout[y + 1][x] == 'E')
		return (1);
	if (layout[y - 1][x] == 'E')
		return (1);
	/* while (index <= range)
	{
		if (layout[y + index][x] == '1' || layout[y + index][x] == 'P')
			return (0);
		if (layout[y][x + index] == '1' || layout[y][x + index] == 'P')
			return (0);
		index++;
	}
	index = 0;
	while (index <= range)
	{
		if (layout[y - index][x] == '1' || layout[y - index][x] == 'P')
			return (0);
		if (layout[y][x - index] == '1' || layout[y][x - index] == 'P')
			return (0);
		index++;
	} */
	return (0);
}

void	new_enemy(t_game *game, int x, int y)
{
	t_enemy	*begin;
	t_enemy	*new_item;

	new_item = (t_enemy *) ft_calloc(1, sizeof(t_enemy));
	new_item->x = x;
	new_item->y = y;
	new_item->sprites[0].w = 80;
	new_item->sprites[0].h = 96;
	load_img(&new_item->sprites[0], "./imgs/enemy.xpm", game);
	begin = game->enemies;
	while (begin && begin->next)
		begin = begin->next;
	if (begin)
		begin->next = new_item;
	else
		game->enemies = new_item;
}

void	enemy_config(t_game *game)
{
	int		y;
	int		x;
	int		x_holder;

	y = game->map.h;
	x = game->map.w;
	x_holder = x;
	while (y--)
	{
		while (x--)
		{
			if (check_surround(y, x, game))
				new_enemy(game, x, y);
		}
		x = x_holder;
	}
}
