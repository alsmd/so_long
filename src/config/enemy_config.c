/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:16:13 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 19:31:48 by flavio           ###   ########.fr       */
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
	if (layout[y][x] != '0')
		return (0);
	if (layout[y][x - 1] == 'C')
		return (1);
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
	new_item->sprites[1].w = 122;
	new_item->sprites[1].h = 103;
	new_item->sprites[2].w = 86;
	new_item->sprites[2].h = 110;
	load_img(&new_item->sprites[0], "./imgs/enemy.xpm", game);
	load_img(&new_item->sprites[1], "./imgs/enemy2.xpm", game);
	load_img(&new_item->sprites[2], "./imgs/enemy3.xpm", game);
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
	int		number;

	number = 0;
	y = game->map.h;
	x = game->map.w;
	x_holder = x;
	while (y--)
	{
		while (x--)
		{
			if (check_surround(y, x, game) && number < 10)
			{
				new_enemy(game, x, y);
				number++;
			}
		}
		x = x_holder;
	}
}
