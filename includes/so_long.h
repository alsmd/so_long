/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:21:04 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 09:34:17 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

/*INCLUDES*/
#include "../mlx/mlx.h"


/*DEFINES*/
# define SO_LONG_H
# define W 119
# define A 97
# define S 115
# define D 100
# define BLOCK_SIZE 64

/*STRUCTS*/
typedef	struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;


typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endin;
}	t_data;

typedef struct s_map
{
	char	*layout;
	t_data	full_map;
	t_data	map;
	int		x;
	int		y;
}	t_map;

typedef struct s_player
{
	t_data	sprites[4];
	int		frame;
	int		x;
	int		y;
	int		step;
}	t_player;

typedef struct s_item
{
	t_data	sprites[4];
	int		x;
	int		y;
}	t_item;

typedef struct	s_game
{
	t_vars		vars;
	t_player	player;
	t_map		map;
	t_item		*items;
	int			width;
	int			height;
	int			block_size;
}	t_game;



/*Prototypes*/


#endif