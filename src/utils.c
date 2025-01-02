/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:48 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/02 11:40:00 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// free a tab of tab (matrix) fully
int	free_all(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	return (0);
}

char	*dup_temp(const char *s1)
{
	size_t	size;
	char	*dup;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + 1;
	dup = (char *)malloc(size * sizeof(char));
	i = 0;
	j = 0;
	if (!(dup))
		return (0);
	while (s1[i])
	{
		if (s1[i] != '\n')
		{
			dup[j] = s1[i];
			j++;
		}
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

/* handle closing with the x and ESC button */
void	handling_close(t_data *data, t_img *img)
{
	free_sprites(&data);
	free_all(data->matrix.map);
	mlx_destroy_window(data->xvar, data->window);
	mlx_destroy_display(data->xvar);
	free(data->xvar);
	free(data);
	ft_printf("Game is closed, see u ! <3\n");
	exit(EXIT_FAILURE);
}
void	free_sprites(t_data *data)
{
	mlx_destroy_image(data->xvar, data->wall.image);
	mlx_destroy_image(data->xvar, data->floor.image);
	mlx_destroy_image(data->xvar, data->item.image);
	mlx_destroy_image(data->xvar, data->cat_left.image);
	mlx_destroy_image(data->xvar, data->cat_right.image);
	mlx_destroy_image(data->xvar, data->cat_back.image);
	mlx_destroy_image(data->xvar, data->esc_final.image);
	mlx_destroy_image(data->xvar, data->esc.image);
}

// CHECK ! handle closing with the ESC key
int	handling_key(int key)
{
	if (key == ESC)
		exit(0);
	return (0);
}