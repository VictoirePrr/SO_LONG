/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:31:55 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/12 17:37:20 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define WALL '1'
# define EMPTY '0'

typedef struct s_data
{
	void	*xvar;
	void	*window;
	int		size_x;
	int		size_y;
}			t_data;

typedef struct s_matrix
{
	char	**map;
	size_t	htl;
	size_t	vtl;
}			t_matrix;

typedef struct s_img
{
	void	*image;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

// so_long.c
int			main(void);

// utils
int			free_all(char **matrix);
char		*dup_temp(const char *s1);

// handling_error
void		print_error(void);
void		print_mess(char *message);

// fill_map
char		**read_map(const char *file, t_matrix *matrix);

// check_items
int			parsing_map(t_matrix *matrix);

// check_map
int			check_rectangle(t_matrix *matrix);
int			check_walls(t_matrix *matrix);
#endif