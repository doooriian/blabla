/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:06:09 by dley              #+#    #+#             */
/*   Updated: 2024/04/15 12:43:47 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		collectibles;
	int		character;
	int		exit;
	int		invalid_letter;
	char	**map;
	bool	**visited;
	int		x_start;
	int		y_start;
	bool	found_exit;
	int		vector_x;
	int		vector_y;
	void	*img;
	int		xpm_height;
	int		xpm_width;
	int		moves;
	int		items;
	char	*player;
}	t_data;

bool	check_input(char *input);
bool	check_height(char *input, t_data *data);
bool	check_wall(t_data *data);
bool	check_width(t_data *data);
bool	check_letters(t_data *data);
bool	check_map(char *input, t_data *data);
void	cpy_map(char *input, t_data *data);
void	count_letters(t_data *data);
void	data_init(t_data *data);
void	ft_error(int i);
void	ft_free_error(int i, t_data *data);
int		error_malloc_map(void);
void	free_visited(t_data *data);
int		free_map(t_data *data);
int		ft_exit(t_data *data);
int		game_init(t_data *data);
void	init_map(t_data *data);
void	get_image(t_data *data, char c);
int		on_destroy(t_data *data);
int		on_keypress(int keycode, void *data);
int		check_move(t_data *data, int dir);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
void	put_exit(t_data *data);
int		get_j(t_data *data, int dir);
int		get_i(t_data *data, int dir);

#endif