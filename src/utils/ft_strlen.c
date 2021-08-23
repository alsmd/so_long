/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavio <flavio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:44:45 by flavio            #+#    #+#             */
/*   Updated: 2021/08/23 10:52:07 by flavio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int		ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] && s[index] != '\n')
		index++;
	return (index);
}
