/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:21:21 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/07 10:14:17 by vicperri         ###   ########lyon.fr   */
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
	size_t size;
	char *dup;
	size_t i;
	size_t j;

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