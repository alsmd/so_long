/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:44:31 by flavio            #+#    #+#             */
/*   Updated: 2021/08/24 10:02:17 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	new_item(t_game *game, int x, int y)
{
	t_item	*begin;
	t_item	*new_item;

	new_item = (t_item *) ft_calloc(1, sizeof(t_item));
	new_item->x = x;
	new_item->y = y;
	item_sprites(new_item, game);
	begin = game->items;
	while (begin && begin->next)
		begin = begin->next;
	if (begin)
		begin->next = new_item;
	else
		game->items = new_item;
}
