/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:38:39 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/06 14:49:11 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// See "documentation.md" for more details on the so_long algorithm.

#include "so_long.h"

int	check_argv(char *argv)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(argv);
	if (len == 4)
		return (1);
	i = 0;
	res = ft_strnstr(argv, ".ber", len);
	if (res)
	{
		while (argv[i])
		{
			if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e'
				&& argv[i + 3] == 'r')
			{
				if (i == len)
					return (0);
			}
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	if (argc != 2 || check_argv(argv[1]) == 1)
		return (print_error(), ft_printf("I need a map dummy...\n"), 0);
	data.matrix.map = read_map(argv[1], &data.matrix);
	if (!data.matrix.map)
		return (print_error(), ft_printf("I need a map dummy...\n"), 0);
	if (parsing_map(&data.matrix) == 1)
		return (print_error(), ft_printf("Ur map is not good honey.\n"), 0);
	data.matrix.map = read_map(argv[1], &data.matrix);
	initialize_window(&data, &data.matrix);
	initialize_img(&data, &img);
	start_game(&data);
	play_game(&data);
	mlx_hook(data.window, 17, 0, handling_close, &data);
	mlx_loop(data.xvar);
	return (0);
}
