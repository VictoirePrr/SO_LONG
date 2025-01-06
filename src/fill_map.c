/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:31:55 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/06 13:28:43 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHECK ! fill the matrix you created
char	**fill_the_matrix(const char *file, t_matrix *matrix)
{
	int		fd;
	char	*temp;

	temp = NULL;
	matrix->vtl = 0;
	fd = open(file, O_RDONLY); // open but this time to fill each rows
	if (fd < 0)
		return (NULL);
	temp = get_next_line(fd);
	while (temp != NULL) // fill each rows
	{
		matrix->map[matrix->vtl] = dup_temp(temp); // fill without the \n
		free(temp);
		if (!matrix->map[matrix->vtl])
			return (free_all(matrix->map), close(fd), NULL);
		matrix->vtl += 1; // go to the next row
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (matrix->map);
}

// CHECK ! create the matrix with your map.ber
char	**read_map(const char *file, t_matrix *matrix)
{
	int		fd;
	char	*temp;

	temp = NULL;
	matrix->vtl = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	temp = get_next_line(fd);
	while (temp != NULL) // get your rows
	{
		matrix->vtl++;
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
	}
	close(fd);
	matrix->map = malloc((matrix->vtl + 1) * sizeof(char *));
	// put them in your matrix
	if (!matrix->map)
		return (NULL);
	matrix->map[matrix->vtl] = NULL;
	if (!fill_the_matrix(file, matrix))
		return (free_all(matrix->map), NULL);
	return (matrix->map);
}
