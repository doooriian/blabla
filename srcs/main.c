/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:27:02 by dley              #+#    #+#             */
/*   Updated: 2024/04/15 12:49:57 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	data_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->height = 0;
	data->width = 0;
	data->collectibles = 0;
	data->character = 0;
	data->exit = 0;
	data->invalid_letter = 0;
	data->map = NULL;
	data->visited = NULL;
	data->x_start = -1;
	data->y_start = -1;
	data->found_exit = 0;
	data->vector_x = 0;
	data->vector_y = 0;
	data->img = NULL;
	data->xpm_height = 64;
	data->xpm_width = 64;
	data->moves = 0;
	data->items = 0;
	data->player = "xpm/playerRight.xpm";
}

int	on_keypress(int keycode, void *data)
{
	if (keycode == 65307)
		return (ft_exit(data));
	else if (keycode == 119 || keycode == 65362)
		return (move_up(data));
	else if (keycode == 115 || keycode == 65364)
		return (move_down(data));
	else if (keycode == 97 || keycode == 65361)
		return (move_left(data));
	else if (keycode == 100 || keycode == 65363)
		return (move_right(data));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nIncorrect number of arguments! It must be 2!\n");
		return (0);
	}
	data_init(&data);
	if (argc == 2 && check_map(argv[1], &data))
	{
		game_init(&data);
		mlx_key_hook(data.win_ptr, &on_keypress, &data);
		mlx_hook(data.win_ptr, 17, 0, &ft_exit, &data);
		mlx_loop(data.mlx_ptr);
	}
}
