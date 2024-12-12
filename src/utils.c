/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:40:48 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 15:12:10 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// CHECK !
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
	size_t size;
	char *dup;
	size_t i;

	size = ft_strlen(s1) + 1;
	dup = (char *)malloc(size * sizeof(char));
	i = 0;
	if (!(dup))
		return (0);
	while (s1[i])
	{
		if (s1[i] != '\n')
			dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}