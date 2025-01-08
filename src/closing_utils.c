/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:48 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/08 10:46:45 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handling_close(t_data *data)
{
	if (data)
	{
		free_sprites(data);
		if (data->matrix.map)
			free_all(data->matrix.map);
		if (data->xvar && data->window)
			mlx_destroy_window(data->xvar, data->window);
		if (data->xvar)
		{
			mlx_destroy_display(data->xvar);
			free(data->xvar);
		}
	}
	ft_printf("Game is closed, see u ! <3\n");
	exit(0);
}

void	free_sprites(t_data *data)
{
	if (data->wall.image)
		mlx_destroy_image(data->xvar, data->wall.image);
	if (data->floor.image)
		mlx_destroy_image(data->xvar, data->floor.image);
	if (data->item.image)
		mlx_destroy_image(data->xvar, data->item.image);
	if (data->cat_left.image)
		mlx_destroy_image(data->xvar, data->cat_left.image);
	if (data->cat_right.image)
		mlx_destroy_image(data->xvar, data->cat_right.image);
	if (data->cat_back.image)
		mlx_destroy_image(data->xvar, data->cat_back.image);
	if (data->esc_final.image)
		mlx_destroy_image(data->xvar, data->esc_final.image);
	if (data->esc.image)
		mlx_destroy_image(data->xvar, data->esc.image);
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
		ft_printf("You've done %d moves\n", data->player_moves);
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
		handling_close(data);
	return (0);
}

int	handling_key(int key)
{
	if (key == ESC)
		exit(0);
	return (0);
}
