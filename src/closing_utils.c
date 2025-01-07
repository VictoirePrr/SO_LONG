/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:48 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/07 10:13:59 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handling_close(t_data *data)
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
		// free(data);
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

int	handling_key(int key)
{
	if (key == ESC)
		exit(0);
	return (0);
}