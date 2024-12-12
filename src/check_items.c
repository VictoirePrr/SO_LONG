/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:31:15 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 17:30:45 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHECK !!check every items to see if there is no stranger
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
// CHECK !! count your items to see if there is enough or too much
int	err_items_count(t_matrix *matrix)
{
	int	counts[3];

	counts[0] = 0; // item
	counts[1] = 0; // player
	counts[2] = 0; // exit
	matrix->vtl = 0;
	while (matrix->map[matrix->vtl])
	{
		matrix->htl = 0;
		while (matrix->map[matrix->vtl][matrix->htl])
		{
			if (matrix->map[matrix->vtl][matrix->htl] == ITEM)
				counts[0]++;
			if (matrix->map[matrix->vtl][matrix->htl] == PLAYER)
				counts[1]++;
			if (matrix->map[matrix->vtl][matrix->htl] == EXIT)
				counts[2]++;
			matrix->htl++;
		}
		matrix->vtl++;
	}
	if (counts[0] < 1 || counts[1] != 1 || counts[2] != 1)
		return (1);
	return (0);
}
// CHECK !! regroup all your parsing honeyyyy
int	parsing_map(t_matrix *matrix)
{
	if (err_items(matrix) == 1)
		return (print_error(),
			print_mess("Map contains items that are not handled !"), 1);
	if (err_items_count(matrix) == 1)
		return (print_error(),
			print_mess("Map contains not enough or too much items !"), 1);
	if (check_rectangle(matrix) == 1)
		return (print_error(), print_mess("Map should be a rectangle !"), 1);
	if (check_walls(matrix) == 1)
	{
		print_error();
		return (print_mess("Map should be encased in walls !"), 1);
	}
	return (0);
}
