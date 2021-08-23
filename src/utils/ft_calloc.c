/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:43:55 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 10:39:10 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	int		index;

	index = 0;
	if (nmemb * size > INT_MAX)
	{
		errno = 12;
		return (0);
	}
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
		{
			((char *)r)[index] = 0;
			index++;
		}
		return (r);
	}
	return (0);
}
