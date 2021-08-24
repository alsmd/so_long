/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:21:43 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 09:13:52 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		w;
	
	if (argc == 2)
	{
		if (check_map(argv[1], &game))
			game_config(&game);
		else
			return (1);
		game_init(&game);
	}
	else
		return (1);
	return (0);
}
