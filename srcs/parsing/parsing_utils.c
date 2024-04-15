/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dley <dley@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:33:15 by dley              #+#    #+#             */
/*   Updated: 2024/04/15 12:34:40 by dley             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	cpy_map(char *input, t_data *data)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = 0;
	fd = open(input, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
	{
		error_malloc_map();
		return ;
	}
	while (i <= data->height)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		len = ft_strlen(data->map[i]);
		if (len > 0 && data->map[i][len - 1] == '\n')
			data->map[i][len - 1] = '\0';
		i++;
	}
	close(fd);
}

void	count_letters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles++;
			else if (data->map[i][j] == 'P')
			{
				data->character++;
				data->x_start = j;
				data->y_start = i;
			}
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] != '1' && data->map[i][j] != '0')
				data->invalid_letter++;
			j++;
		}
		i++;
	}
}
