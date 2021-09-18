/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:41:00 by user42            #+#    #+#             */
/*   Updated: 2021/09/18 13:35:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_ex(char *file)
{
    int index;

    index = ft_strlen(file);
    if (index-- < 4)
        return (0);
    if (file[index--] != 'r' || file[index--] != 'e' || file[index--] != 'b')
        return (0);
    if (file[index] != '.')
        return (0);
    return (1);
}

int check_surround_wall(t_game *game)
{
    char    **layout;
    int     x;
    int     y;

    x = game->map.w;
    y = game->map.h;
    layout = game->map.layout;
    while (x--)
    {
        if (layout[0][x] != '1')
            return (0);
        if (layout[y - 1][x] != '1')
            return (0);
    }
    x = game->map.w - 1;
    while (y--)
    {
        if (layout[y][0] != '1')
            return (0);
        if (layout[y][x] != '1')
            return (0);
    }
    return (1);
}

int check_structure(t_game *game)
{
	int	x;
	int	x_hold;
	int	y;
	int	check[3];

	x = game->map.w;
	x_hold = game->map.w;
	y = game->map.h;
	check[0] = 0;
	check[1] = 0;
	check[2] = 0;
	while (y--)
	{
		while (x--)
		{
			if (game->map.layout[y][x] == 'C')
				check[0] = 1;
			if (game->map.layout[y][x] == 'P')
				check[1] = 1;
			if (game->map.layout[y][x] == 'E')
				check[2] = 1;
		}
		x = x_hold;
	}
	return (check[0] && check[1] && check[2]);
}
