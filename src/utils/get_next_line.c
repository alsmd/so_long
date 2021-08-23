/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:16:16 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 10:46:46 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	get_line_size(char	*data)
{
	size_t	size;

	size = 0;
	while (data[size] && data[size] != '\n')
		size++;
	if (data[size] == '\n')
		size++;
	return (size);
}

int	append_line(char *line, char *data)
{
	int		index;
	int		sub_index;

	sub_index = 0;
	index = 0;
	while (line[index])
		index++;
	while (data[sub_index])
	{
		line[index + sub_index] = data[sub_index];
		if (data[sub_index] == '\n')
			return (sub_index + 1);
		sub_index++;
	}
	return (-1);
}

void	get_line(t_buffer *buffer)
{
	size_t	size;
	char	*tmp;
	int		desloc;

	desloc = buffer->desloc;
	size = get_line_size(&buffer->data[desloc]);
	if (buffer->line)
		size += get_line_size(buffer->line);
	tmp = (char *) ft_calloc(size + 1, sizeof(char));
	if (buffer->line)
	{
		append_line(tmp, buffer->line);
		free(buffer->line);
	}
	desloc = append_line(tmp, &buffer->data[desloc]);
	buffer->line = tmp;
	if (desloc == -1)
	{
		ft_bzero(buffer->data, BUFFER_SIZE);
		buffer->desloc = 0;
		if ((read(buffer->fd, buffer->data, BUFFER_SIZE)) > 0)
			get_line(buffer);
	}
	else
		buffer->desloc += desloc;
}

char	*get_next_line(int fd)
{
	static t_buffer	list[255];
	t_buffer		*buffer;

	if (fd < 0 || fd > 255)
		return (0);
	buffer = &list[fd];
	buffer->fd = fd;
	buffer->line = 0;
	if (*buffer->data == 0)
	{
		if ((read(fd, buffer->data, BUFFER_SIZE)) <= 0)
			return (0);
	}
	get_line(buffer);
	if (*buffer->line == 0)
	{
		free(buffer->line);
		return (0);
	}
	return (buffer->line);
}
