/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:38:39 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/02 12:11:48 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// See "documentation.md" for more details on the so_long algorithm.

#include "so_long.h"

int	main(void)
{
	char	*file;
	t_data	data;
	t_img	img;

	file = "map.ber";
	// Parse the map and initialize matrix
	data.matrix.map = read_map(file, &data.matrix);
	if (parsing_map(&data.matrix) == 0)
		printf("good job honey, ur map is good !\n");
	else
		return (0);
	// re-read the map after flood fill
	data.matrix.map = read_map(file, &data.matrix);
	// Initialize the game
	initialize_window(&data, &data.matrix);
	initialize_img(&data, &img);
	// Start the game
	start_game(&data);
	play_game(&data);
	// Handle closing
	mlx_hook(data.window, 17, 0, handling_close, &data);
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, handling_close,
		&data);
	// Start the MLX loop
	mlx_loop(data.xvar);
	free_all(data.matrix.map);
	return (0);
}
