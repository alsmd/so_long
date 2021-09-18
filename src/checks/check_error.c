/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:23:01 by flavio            #+#    #+#             */
/*   Updated: 2021/09/18 12:35:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_error(int error)
{
    if (error == INVALID_MAP)
        printf("The given map is invalid!\n");
    if (error == INVALID_PARAM_NB)
        printf("Parameter's number must be 1\n");
    return (error);
}
