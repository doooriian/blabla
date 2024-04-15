/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:26:16 by dley              #+#    #+#             */
/*   Updated: 2024/04/10 19:59:07 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_visited(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->visited = malloc(sizeof(bool *) * data->height);
	while (i < data->height)
	{
		data->visited[i] = malloc(sizeof(bool) * data->width);
		j = 0;
		while (j < data->width)
		{
			data->visited[i][j] = false;
			j++;
		}
		i++;
	}
}

void	mark_access(t_data *data, int x, int y, int *found_collec)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height
		|| data->map[y][x] == '1' || data->visited[y][x])
		return ;
	data->visited[y][x] = true;
	if (data->map[y][x] == 'C')
		(*found_collec)++;
	mark_access(data, x + 1, y, found_collec);
	mark_access(data, x - 1, y, found_collec);
	mark_access(data, x, y + 1, found_collec);
	mark_access(data, x, y - 1, found_collec);
}

bool	is_exit_access(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' && data->visited[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	check_way_possible(t_data *data)
{
	int		found_collectibles;
	bool	exit_access;

	init_visited(data);
	found_collectibles = 0;
	mark_access(data, data->x_start, data->y_start, &found_collectibles);
	exit_access = is_exit_access(data);
	free_visited(data);
	return (exit_access && found_collectibles == data->collectibles);
}

bool	check_map(char *input, t_data *data)
{
	if (!check_input(input))
		return (ft_error(1), 0);
	if (!check_height(input, data))
		return (ft_error(2), 0);
	cpy_map(input, data);
	if (!check_width(data))
		return (ft_free_error(3, data), 0);
	if (data->height > data->width)
		return (ft_free_error(4, data), 0);
	if (!check_wall(data))
		return (ft_free_error(5, data), 0);
	if (!check_letters(data))
		return (ft_free_error(6, data), 0);
	if (!check_way_possible(data))
		return (ft_free_error(7, data), 0);
	if (data->height > 21 || data->width > 40)
		return (ft_free_error(8, data), 0);
	return (1);
}
