/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:41:00 by user42            #+#    #+#             */
/*   Updated: 2021/09/18 12:45:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_ex(char *file)
{
    int index;

    index = ft_strlen(file);
    if (index-- < 4)
        return (0);
    if (file[index--] != 'r' || file[index--] != 'e' || file[index--] != 'b')
        return (0);
    if (file[index] != '.')
        return (0);
    return (1);
}
