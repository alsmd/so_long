/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:21:04 by flavio            #+#    #+#             */
/*   Updated: 2021/08/26 17:32:08 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

/*INCLUDES*/
#include "../mlx/mlx.h"
#include "get_next_line.h"
#include <X11/X.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
/*DEFINES*/
# define SO_LONG_H
# define W 119
# define A 97
# define S 115
# define D 100
# define BLOCK_SIZE 64
# define OBJECTS "EC01P"

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
	char	**layout;
	t_data	full_map;
	t_data	map;
	int		x;
	int		y;
	int		w;
	int		h;
}	t_map;

typedef struct s_player
{
	t_data	sprites[4];
	int		frame;
	int		x;
	int		y;
	int		steps;
	int		w;
	int		h;
}	t_player;

typedef struct s_item
{
	t_data	sprites[4];
	int				x;
	int				y;
	float			frame;
	int				going_up;
	struct s_item	*next;
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

//General
void	game_config(t_game *game);
void	game_init(t_game *game);
int		key_hook(int keycode, t_game *game);

//Frames
int		frame_update(t_game *game);

//MAP
void	map_config(t_game *game);
int	 	check_map(char	*map_path, t_game *game);
void	map_sprites(t_game *game);
void	get_active_map(t_game *game);

//PLAYER
void	player_config(t_game *game);
void	player_sprites(t_game *game);
void	player_action(int keycode, t_game *game);
int		check_mov(t_game *game, int x, int y);

//Item
void	new_item(t_game *game, int x, int y);
void	item_sprites(t_item *item, t_game *game);

//Utils
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_in(char *str, char c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_get_pixel(t_data *data, int x, int y);
void	copy_img_from(t_data *dest, t_data *src, int x_src, int y_src, int width, int height);
void	copy_img_to(t_data *dest, t_data *src, int x_dest, int y_dest, int width, int height);
void	clear_image(t_data *img, int width, int height, int color);
#endif