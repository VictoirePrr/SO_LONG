/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:11:20 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/02 09:54:19 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_matrix *matrix, int x, int y)
{
	// Ensure x and y are within bounds of the map
	if (x < 0 || x >= matrix->vtl || y < 0 || y >= matrix->htl)
		return ;
	// Stop if the cell is a wall or already visited
	if (matrix->map[x][y] == WALL || matrix->map[x][y] == 'X')
		return ;
	matrix->map[x][y] = 'X';
	flood_fill(matrix, x - 1, y);
	flood_fill(matrix, x + 1, y);
	flood_fill(matrix, x, y - 1);
	flood_fill(matrix, x, y + 1);
}

int	check_player_access(t_matrix *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix->vtl)
	{
		y = 0;
		while (y < matrix->htl)
		{
			if (matrix->map[x][y] == PLAYER)
			{
				flood_fill(matrix, x, y);
				break ;
			}
			y++;
		}
		x++;
	}
	return (final_check(matrix));
}
int	final_check(t_matrix *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < matrix->vtl)
	{
		y = 0;
		while (y < matrix->htl)
		{
			if (matrix->map[x][y] == ITEM || matrix->map[x][y] == EXIT)
			{
				if (matrix->map[x][y] != 'X')
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
