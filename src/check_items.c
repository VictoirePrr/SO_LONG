/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:15 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:08 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	err_items(t_matrix *matrix)
{
	matrix->vtl = 0;
	while (matrix->map[matrix->vtl])
	{
		matrix->htl = 0;
		while (matrix->map[matrix->vtl][matrix->htl])
		{
			if (!ft_strchr("CPE01", matrix->map[matrix->vtl][matrix->htl]))
				return (1);
			matrix->htl++;
		}
		matrix->vtl++;
	}
	return (0);
}

int	err_items_count(t_matrix *matrix)
{
	int	counts[2];

	matrix->total_item = 0;
	counts[0] = 0;
	counts[1] = 0;
	matrix->vtl = 0;
	while (matrix->map[matrix->vtl])
	{
		matrix->htl = 0;
		while (matrix->map[matrix->vtl][matrix->htl])
		{
			if (matrix->map[matrix->vtl][matrix->htl] == ITEM)
				matrix->total_item++;
			if (matrix->map[matrix->vtl][matrix->htl] == PLAYER)
				counts[0]++;
			if (matrix->map[matrix->vtl][matrix->htl] == EXIT)
				counts[1]++;
			matrix->htl++;
		}
		matrix->vtl++;
	}
	if (matrix->total_item < 1 || counts[0] != 1 || counts[1] != 1)
		return (1);
	return (0);
}

int	parsing_map(t_matrix *matrix)
{
	if (err_items(matrix) == 1)
		return (print_error(),
			ft_printf("Map contains items that are not handled !\n"), 1);
	if (err_items_count(matrix) == 1)
		return (print_error(),
			ft_printf("Map contains not enough or too much items !\n"), 1);
	if (check_rectangle(matrix) == 1)
		return (print_error(), ft_printf("Map should be a rectangle !\n"), 1);
	if (check_walls(matrix) == 1)
		return (print_error(), ft_printf("Map should be encased in walls !\n"),
			1);
	if (check_player_access(matrix) == 1)
		return (print_error(), ft_printf("The flood fill indicates an error !\n"),
			1);
	free_all(matrix->map);
	return (0);
}
