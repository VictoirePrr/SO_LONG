/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:21:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/08 10:45:53 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	ft_printf("Error\n");
}

void	free_all(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

char	*dup_temp(const char *s1)
{
	size_t	size;
	char	*dup;
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
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
