/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:13:35 by flavio            #+#    #+#             */
/*   Updated: 2021/07/29 14:47:00 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static size_t	get_size(int n)
{
	size_t	index;

	index = 0;
	while (n)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

static char	*set_string(unsigned int n, size_t size, int is_negative)
{
	char	*string;

	if (is_negative)
		size++;
	string = (char *) ft_calloc(size + 1, sizeof(char));
	if (!string)
		return (0);
	while (size > 0)
	{
		string[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	if (is_negative)
		string[0] = '-';
	return (string);
}

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	number;
	int				is_negative;

	is_negative = 0;
	if (n < 0)
	{
		number = n * -1;
		is_negative = 1;
	}
	else
		number = n;
	size = get_size(number);
	if (number == 0)
		size = 1;
	return (set_string(number, size, is_negative));
}