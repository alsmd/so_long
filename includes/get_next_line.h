/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:16:09 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 09:52:47 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>

/*
	@param fd		File Descriptor
	@param data		Where the buffer's content will stay.
	@param desloc	From which position we must read from data.
					If the buffer is "hello\\nworld\\0" and we already
					read "hello\\n", we must read from "w" of "world\\0".
	@param line		The line that will be returned.
*/
typedef struct s_buffer
{
	int				fd;
	char			data[BUFFER_SIZE + 1];
	int				desloc;
	char			*line;
}	t_buffer;

//BUFFER MANIPULATION
/*
	@param	fd	File Descriptor where the Content will come from.
	@brief		Will get the next line from the "fd" and return it.
	@return		The next line, or 0 on any error.

*/
char			*get_next_line(int fd);

/*
	@param data		buffer's content where the line will be.
	@brief			Will get the next line's size from "data".
					A line can be finished for a "\0" or "\n",
					if its a "\n" it will be included in size.
	@return 		returns the line's size.
	
*/
size_t			get_line_size(char	*data);

/*
	@param line		Where the content will be append.
	@param data		The content to be append in "line".
	@brief			Function will append "data" to "line",
					starting from the first null in line.
	@return			Will return the number of characters copied
					from data to line or -1 if the last character copied
					wasn't "\n".
*/
int				append_line(char *line, char *data);

/*
	@param	buffer		A struct that contains basic informations
						that will be used to get the line
	@brief				1* It will get the line (null or \\n termineted) from
						"&buffer->data[buffer->desloc]" and copy  to "buffer->line".
						2* If othe line ended with "\\0" intead of "\\n"
						the "buffer->data" will be refilled.
						2.1* And if there was more content inside "fd" this content will
						be concatenated to "buffer->line" until "\\n" or "\\0", and the 
						process "2*" will be repeted.
*/
void			get_line(t_buffer *buffer);

//UTILITIES
/*
	@param (nmemb)	Number of elements;
	@param (size)	Size of each element;
	@brief			Allocates memory for an array of nmemb elements of size
					bytes each and returns a pointer to the allocated memory.
					The memory is set to zero. If nmemb or size is 0, then
					calloc() return either null, or a unique pointer,
					value that can be later be passed to free().
					Both interpreted as unsigned char.
	@return			Returns a pointer to the allocated memory,
					on error return null, null may also be returned if
					size or nmemb is zero.
*/
void			*ft_calloc(size_t nmemb, size_t size);

/*
	@param (s)		Pointer to the memory area.
	@param (n)		Quantity of bytes that will be erased.
	@brief			Erases the data in the n bytes of the memory stating at the
					location pointed to by s, by writing zeroes.
	@return			Returns a pointer to the memory area s.
*/
void			ft_bzero(void *s, size_t n);
#endif