/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:16:58 by dley              #+#    #+#             */
/*   Updated: 2024/04/10 17:31:17 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit(t_data *data)
{
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_map(data);
	exit (0);
}

int	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}

void	free_visited(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
}
