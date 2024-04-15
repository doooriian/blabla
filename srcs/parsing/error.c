/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:25:59 by dley              #+#    #+#             */
/*   Updated: 2024/04/15 12:43:30 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("Error\nCan't find the map\n");
	else if (i == 2)
		ft_printf("Error\nNot enough lines\n");
}

void	ft_free_error(int i, t_data *data)
{
	free_map(data);
	if (i == 3)
		ft_printf("Error\nEach lines must have the same length\n");
	else if (i == 4)
		ft_printf("Error\nMap must be rectangular\n");
	else if (i == 5)
		ft_printf("Error\nMap must be closed by walls\n");
	else if (i == 6)
	{
		ft_printf("Error\nMap must contain :\n- one 'P' (player)\n");
		ft_printf("- one 'E' (exit)\n- at least one 'C' (collectibles)\n");
		ft_printf("- and several '0' and '1' for spaces and walls\n");
	}
	else if (i == 7)
		ft_printf("Error\nMap can't be finished, no way found\n");
	else if (i == 8)
		ft_printf("Error\nMap is too big\n");
}

int	error_malloc_map(void)
{
	ft_printf("Error\n Malloc of the map didn't work\n");
	exit (0);
}
