/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:05 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/08 10:46:51 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *data)
{
	size_t	vtl;
	size_t	htl;

	vtl = 0;
	while (data->matrix.map[vtl])
	{
		htl = 0;
		while (data->matrix.map[vtl][htl])
		{
			handle_img(data, vtl, htl);
			htl++;
		}
		vtl++;
	}
	play_game(data);
}

int	handle_exit(t_data *data, int new_x, int new_y)
{
	if (data->matrix.total_item == 0)
	{
		put_img_to_window(data, data->floor, data->size_x, data->size_y);
		data->matrix.map[data->size_x][data->size_y] = EMPTY;
		put_img_to_window(data, data->esc_final, new_x, new_y);
		ft_printf("Kitty has successfully escaped! You win <3\n");
	}
	else
		ft_printf("Oh nooo, kitty is still hungry! Looser :(\n");
	return (1);
}

int	move_player(t_data *data, int new_x, int new_y, t_img player_img)
{
	if (new_x >= 0 && new_x < (int)data->matrix.vtl && new_y >= 0
		&& new_y < (int)data->matrix.htl
		&& data->matrix.map[new_x][new_y] != WALL)
	{
		put_img_to_window(data, data->floor, data->size_x, data->size_y);
		if (data->matrix.map[new_x][new_y] == ITEM)
			data->matrix.total_item--;
		data->matrix.map[data->size_x][data->size_y] = EMPTY;
		data->matrix.map[new_x][new_y] = PLAYER;
		data->size_x = new_x;
		data->size_y = new_y;
		put_img_to_window(data, player_img, new_x, new_y);
		return (1);
	}
	return (0);
}

void	decide_path(t_data *data, int new_x, int new_y, t_img player_img)
{
	if (data->matrix.map[new_x][new_y] == EXIT)
		handle_exit(data, new_x, new_y);
	else
		move_player(data, new_x, new_y, player_img);
}

void	play_game(t_data *data)
{
	data->player_moves = 0;
	mlx_key_hook(data->window, get_key, data);
}
