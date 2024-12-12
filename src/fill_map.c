/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:31:55 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 15:31:27 by vicperri         ###   ########lyon.fr   */
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
	while ((temp = get_next_line(fd)) != NULL) // fill each rows
	{
		matrix->map[matrix->vtl] = dup_temp(temp); // fill without the \n
		if (!matrix->map[matrix->vtl])
			free_all(matrix->map);
		matrix->vtl += 1; // go to the next row
	}
	free(temp);
	close(fd);
	return (matrix->map);
}

// CHECK ! create the matrix with your map.ber
char	**read_map(const char *file, t_matrix *matrix)
{
	int		fd;
	int		rows;
	char	*temp;

	temp = NULL;
	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((temp = get_next_line(fd)) != NULL) // get your rows
	{
		rows++;
		free(temp);
	}
	close(fd);
	matrix->map = malloc((rows + 1) * sizeof(char *));
	// put them in your matrix
	if (!matrix->map)
		return (NULL);
	matrix->map[rows] = NULL;
	matrix->map = fill_the_matrix(file, matrix);
	return (matrix->map);
}
