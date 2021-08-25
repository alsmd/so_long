/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:53:47 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 13:02:53 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	item_sprites(t_item *item, t_game *game)
{
	t_data	full_sprite;
	int		w;
	int		h;

	w = BLOCK_SIZE;
	h = BLOCK_SIZE;
	full_sprite.img = mlx_xpm_file_to_image(game->vars.mlx, "./imgs/item.xpm", &w, &h);
	full_sprite.addr = mlx_get_data_addr(full_sprite.img,
						&full_sprite.bits_per_pixel, &full_sprite.line_length,
						&full_sprite.endin);
	item->sprites[0].img = mlx_new_image(game->vars.mlx, w, h);
	item->sprites[0].addr = mlx_get_data_addr(item->sprites[0].img,
						&item->sprites[0].bits_per_pixel,
						&item->sprites[0].line_length,
						&item->sprites[0].endin);
	copy_img_from(&item->sprites[0], &full_sprite, 0, 0, w, h);
}
