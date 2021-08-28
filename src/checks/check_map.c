/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:48:10 by flavio            #+#    #+#             */
/*   Updated: 2021/08/28 10:51:54 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_format(char	*line)
{
	while (*line && *line != '\n')
	{
		if (!is_in(OBJECTS, *line))
			return (0);
		line++;
	}
	return (1);
}

static void	append(char **dest, char *src)
{
	char	*holder;
	int		index;

	index = 0;
	if (*dest == 0)
		*dest = (char *) ft_calloc(ft_strlen(src) + 1, sizeof(char));
	else
	{
		holder = *dest;
		*dest = (char *) ft_calloc(ft_strlen(*dest) + ft_strlen(src) + 1, 1);
		ft_strcat(*dest, holder);
		free(holder);
	}
	ft_strcat(*dest, src);
}

static void	make_layout(t_game *game, int x, int y, char *content)
{
	int	index;

	index = 0;
	game->map.layout = ft_calloc(y, sizeof(char *));
	while (index < y)
	{
		game->map.layout[index] = ft_substr(content, 0, x);
		content += x;
		index++;
	}
	game->map.w = x;
	game->map.h = y;
}

int	get_all_content(int fd, t_game *game)
{
	int		x;
	int		y;
	char	*line;
	char	*all_content;

	x = -1;
	y = 0;
	all_content = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (check_format(line) && (x == -1 || x == ft_strlen(line)))
		{
			if (x == -1)
				x = ft_strlen(line);
			append(&all_content, line);
		}
		else
			return (0);
		y++;
		line = get_next_line(fd);
	}
	make_layout(game, x, y, all_content);
	return (1);
}

int	check_map(char	*map_path, t_game *game)
{
	int		fd;
	int		x;
	int		y;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!(get_all_content(fd, game)))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
