/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:33:20 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 17:38:40 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHECK !! check if the map is indeed a rectangle
int	check_rectangle(t_matrix *matrix)
{
	matrix->vtl = 0;
	matrix->htl = ft_strlen(matrix->map[matrix->vtl]);
	while (matrix->map[matrix->vtl])
	{
		if (matrix->htl != ft_strlen(matrix->map[matrix->vtl]))
			return (1);
		matrix->vtl++;
	}
	if (matrix->htl == matrix->vtl)
		return (1);
	return (0);
}
int	check_first_last_rows(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != WALL)
			return (1);
		i++;
	}
	return (0);
}

// CHECK !! check if the map is enclosed in walls
int	check_walls(t_matrix *matrix)
{
	matrix->vtl = 0;
	matrix->htl = ft_strlen(matrix->map[matrix->vtl]);
	if (check_first_last_rows(matrix->map[0]) == 1) // check first row
		return (1);
	while (matrix->map[matrix->vtl])
	{
		if (matrix->map[matrix->vtl][0] != WALL)
			return (1);
		else if (matrix->map[matrix->vtl][matrix->htl - 1] != WALL)
			return (1);
		matrix->vtl++;
	}
	if (check_first_last_rows(matrix->map[matrix->vtl - 1]) == 1)
		// check last row
		return (1);
	return (0);
}
