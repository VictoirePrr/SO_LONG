/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:31:35 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/13 16:40:22 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    start_game(t_data *data, t_img *image, t_matrix *matrix)
{
	matrix->vtl = 0;
	while (matrix->map[matrix->vtl])
	{
		matrix->htl = 0;
		while (matrix->map[matrix->vtl][matrix->htl])
		{
			if (matrix->map[matrix->vtl][matrix->htl] == ITEM)
				put_image(&data, &img, matrix->vtl, matrix->htl);
			if (matrix->map[matrix->vtl][matrix->htl] == PLAYER)
				counts[1]++;
			if (matrix->map[matrix->vtl][matrix->htl] == EXIT)
				counts[2]++;
			matrix->htl++;
		}
		matrix->vtl++;
	}
    mlx_put_image_to_window(data.xvar, data.window, img.image, 0, 0);
}

void    put_image(t_data *data, &img, int x, int y)