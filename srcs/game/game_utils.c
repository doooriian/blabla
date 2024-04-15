/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:27:26 by dley              #+#    #+#             */
/*   Updated: 2024/04/10 19:28:42 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_exit(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->items == data->collectibles)
	{
		while (data->map[++i])
		{
			j = 0;
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'E')
				{
					data->img = mlx_xpm_file_to_image(data->mlx_ptr, \
"xpm/hoop.xpm", &data->xpm_width, &data->xpm_height);
					if (!data->img)
						ft_exit(data);
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img, j * 64, i * 64);
					mlx_destroy_image(data->mlx_ptr, data->img);
				}
				j++;
			}
		}
	}
}

int	get_j(t_data *data, int dir)
{
	int	j;

	if (dir == 3)
		j = (data->vector_x - 64) / 64;
	else if (dir == 4)
		j = (data->vector_x + 64) / 64;
	else
		j = data->vector_x / 64;
	return (j);
}

int	get_i(t_data *data, int dir)
{
	int	i;

	if (dir == 1)
		i = (data->vector_y - 64) / 64;
	else if (dir == 2)
		i = (data->vector_y + 64) / 64;
	else
		i = data->vector_y / 64;
	return (i);
}
