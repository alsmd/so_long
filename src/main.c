/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:21:43 by flavio            #+#    #+#             */
/*   Updated: 2021/08/27 13:52:50 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		w;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 2)
	{
		if (check_map(argv[1], &game))
			game_config(&game);
		else
			return (check_error(INVALID_MAP));
		game_init(&game);
	}
	else
		return (check_error(INVALID_PARAM_NB));
	return (SUCCESS);
}
