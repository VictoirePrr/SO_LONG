/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:38:39 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 14:28:58 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHECK ! handle closing with the x button
int	handling_close(t_data *data)
{
	mlx_destroy_window(data->xvar, data->window);
	mlx_destroy_display(data->xvar);
	free(data->xvar);
	exit(0);
	return (0);
}

// CHECK ! handle closing with the ESC key
int	handling_key(int key)
{
	if (key == ESC)
		exit(0);
	printf("you pressed the %d key", key);
	return (0);
}


int	main(void)
{
	// char *title;
	char *file;
	// t_data data;
	// t_img img;
	t_matrix matrix;
	// data.size_x = 1920; // !rectangle!
	// data.size_y = 1280; // !rectangle!

	// title = "so_vivi";
	file = "map.ber";

	// // init + open window
	// data.xvar = mlx_init();
	// data.window = mlx_new_window(data.xvar, data.size_x, data.size_y, title);

	// parsing the map
	matrix.map = read_map(file, &matrix);
	if (parsing_map(&matrix) == 0)
	{
		printf("good job honey, ur map is good !");
	}
	else
		// close everything honey exit (0);
		return (0);

	// // image
	// img.image = mlx_xpm_file_to_image(data.xvar, file, &img.width,
	// 		&img.height);
	// mlx_put_image_to_window(data.xvar, data.window, img.image, 0, 0);

	// // closing
	// mlx_destroy_image(data.xvar, img.image);
	// mlx_hook(data.window, 17, 0, handling_close, &data);
	// mlx_key_hook(data.window, handling_key, NULL);
	// // I don´t destroy anything but it works why ??
	// mlx_loop(data.xvar);
	return (0);
}