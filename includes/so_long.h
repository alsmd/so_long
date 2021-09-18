/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:21:04 by flavio            #+#    #+#             */
/*   Updated: 2021/09/18 13:02:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

/*INCLUDES*/
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
/*DEFINES*/
# define SO_LONG_H
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define BLOCK_SIZE 64
# define OBJECTS "EC01P"
/*ENUM*/
enum
{
	SUCCESS,
	INVALID_MAP,
	INVALID_PARAM_NB
};

/*STRUCTS*/
typedef struct s_vars
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
	int		w;
	int		h;
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

typedef struct s_enemy
{
	t_data			sprites[3];
	float			frame;
	int				active;
	int				x;
	int				y;
	int				going_up;
	struct s_enemy	*next;
}	t_enemy;

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
	t_data			sprite;
	int				x;
	int				y;
	float			frame;
	int				going_up;
	struct s_item	*next;
}	t_item;

typedef struct s_fireball
{
	t_data				sprite;
	int					x;
	int					y;
	int					steps;
	struct s_fireball	*next;
}	t_fireball;

typedef struct s_game
{
	t_vars		vars;
	t_player	player;
	t_map		map;
	t_item		*items;
	t_enemy		*enemies;
	t_fireball	*fireballs;
	int			width;
	int			height;
	int			block_size;
	int			game_over;
	int			win;
}	t_game;

/*Prototypes*/

//General
void	game_config(t_game *game);
void	game_init(t_game *game);
void	create_img(t_data *img, int w, int h, t_game *game);
void	load_img(t_data *img, char *path, t_game *game);
void	print_over(t_game *game);
void	check_exit(t_game *game);
void	print_screen(t_game *game);
int		check_error(int error);

//MAP
void	map_config(t_game *game);
int		check_map(char *map_path, t_game *game);
void	get_active_map(t_game *game);
int		check_ex(char *file);
int		check_surround_wall(t_game *game);

//Enemy
void	enemy_config(t_game *game);
void	render_enemies(t_game *game);
void	new_fireball(t_game *game, int x, int y);
void	render_fireball(t_game *game);

//PLAYER
void	player_config(t_game *game);
void	player_action(int keycode, t_game *game);
int		check_mov(t_game *game, int x, int y);
void	render_user(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	check_player_collision(int x, int y, t_game *game);

//Item
void	new_item(t_game *game, int x, int y);
void	render_items(t_game *game);

//Utils
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_strcat(char *dest, char *src);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		is_in(char *str, char c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		my_mlx_get_pixel(t_data *data, int x, int y);

/*
	@param	info[4]		info[0] = x_src, info[1] = y_src,
						info[2] = width, info[3] = height
	@brief				Will copy a piece of the image src starting from x,y and
						cut width and height.
						The image will be past inside dest.
*/
void	copy_img_from(t_data *dest, t_data *src, int info[4]);
/*
	@param	info[4]		info[0] = x_dest, info[1] = y_dest, info[2] = width,
						info[3] = height
	@brief				Will copy width and height from image src and past into dest on 
						cordanites x and y
*/
void	copy_img_to(t_data *dest, t_data *src, int info[4]);
int		*to_array(int x, int y, int w, int h);

void	clear_image(t_data *img, int width, int height, int color);
#endif