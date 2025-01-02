/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:05 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/02 11:44:46 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_window(t_data *data, t_img img, int vtl, int htl)
{
	mlx_put_image_to_window(data->xvar, data->window, img.image, htl
		* img.width, vtl * img.height);
}

void	handle_img(t_data *data, int vtl, int htl)
{
	if (data->matrix.map[vtl][htl] == PLAYER)
	{
		data->size_x = vtl;
		data->size_y = htl;
		put_img_to_window(data, data->cat_left, vtl, htl);
	}
	else if (data->matrix.map[vtl][htl] == WALL)
		put_img_to_window(data, data->wall, vtl, htl);
	else if (data->matrix.map[vtl][htl] == EMPTY)
		put_img_to_window(data, data->floor, vtl, htl);
	else if (data->matrix.map[vtl][htl] == ITEM)
		put_img_to_window(data, data->item, vtl, htl);
	else if (data->matrix.map[vtl][htl] == EXIT)
		put_img_to_window(data, data->esc, vtl, htl);
}

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
	play_game(data); // Call once after initializing the map
}

void	handle_exit(t_data *data, int new_x, int new_y)
{
	if (data->matrix.total_item == 0)
	{
		put_img_to_window(data, data->floor, data->size_x, data->size_y);
		data->matrix.map[data->size_x][data->size_y] = EMPTY;
		put_img_to_window(data, data->esc_final, new_x, new_y);
		ft_printf("Kitty has successfully escaped! You win <3\n"); // End game
	}
	else
	{
		ft_printf("Oh nooo, kitty is still hungry! Looser.\n");
		handling_close(&data, &data);
	}
}

int	move_player(t_data *data, int new_x, int new_y, t_img player_img)
{
	if (new_x >= 0 && new_x < (int)data->matrix.vtl && new_y >= 0
		&& new_y < (int)data->matrix.htl
		&& data->matrix.map[new_x][new_y] != WALL)
	{
		put_img_to_window(data, data->floor, data->size_x, data->size_y);
		if (data->matrix.map[new_x][new_y] == ITEM)
			data->matrix.total_item--; // Decrease item count on collection
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

int	get_key(int key, void *param)
{
	t_data	*data;
	int		new_x;
	int		new_y;

	data = (t_data *)param;
	new_x = data->size_x;
	new_y = data->size_y;
	if (key == UP || key == W || key == DOWN || key == S || key == LEFT
		|| key == A || key == RIGHT || key == D)
	{
		printf("You've done %d moves\n", data->player_moves);
		data->player_moves++;
	}
	if (key == UP || key == W)
		decide_path(data, new_x - 1, new_y, data->cat_back);
	else if (key == DOWN || key == S)
		decide_path(data, new_x + 1, new_y, data->cat_left);
	else if (key == LEFT || key == A)
		decide_path(data, new_x, new_y - 1, data->cat_left);
	else if (key == RIGHT || key == D)
		decide_path(data, new_x, new_y + 1, data->cat_right);
	else if (key == ESC)
		handling_close(&data, &data);
	return (0);
}

void	play_game(t_data *data)
{
	data->player_moves = 0;
	mlx_key_hook(data->window, get_key, data);
}
