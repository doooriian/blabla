/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:47:50 by dley              #+#    #+#             */
/*   Updated: 2024/04/10 19:20:31 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_image(t_data *data, char c)
{
	if (c == '1')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/wall.xpm",
				&data->xpm_width, &data->xpm_height);
	else if (c == '0')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/floor.xpm",
				&data->xpm_width, &data->xpm_height);
	else if (c == 'C')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/ball.xpm",
				&data->xpm_width, &data->xpm_height);
	else if (c == 'P')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, data->player,
				&data->xpm_width, &data->xpm_height);
	else if (c == 'E')
		data->img = mlx_xpm_file_to_image(data->mlx_ptr, "xpm/floor.xpm",
				&data->xpm_width, &data->xpm_height);
	if (!data->img)
		ft_exit(data);
}

void	init_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0')
			{	
				get_image(data, '0');
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img,
					j * 64, i * 64);
				mlx_destroy_image(data->mlx_ptr, data->img);
			}
			get_image(data, data->map[i][j]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img,
				j * 64, i * 64);
			mlx_destroy_image(data->mlx_ptr, data->img);
			j++;
		}
		i++;
	}
}

int	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width * 64,
			data->height * 64, "so_long");
	data->vector_x = data->x_start * 64;
	data->vector_y = data->y_start * 64;
	init_map(data);
	return (1);
}
