/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:31:55 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/08 10:49:34 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define UP 65362
# define RIGHT 65363
# define LEFT 65361
# define DOWN 65364

# define W 119
# define A 97
# define S 115
# define D 100

# define PLAYER 'P'
# define ITEM 'C'
# define EXIT 'E'
# define WALL '1'
# define EMPTY '0'

# define WALL_XPM "sprites/wall.xpm"
# define FLOOR_XPM "sprites/floor.xpm"
# define ITEM_XPM "sprites/item.xpm"
# define CAT_LEFT_XPM "sprites/cat_left.xpm"
# define CAT_RIGHT_XPM "sprites/cat_right.xpm"
# define CAT_BACK_XPM "sprites/cat_back.xpm"
# define ESC_FINAL_XPM "sprites/esc_final.xpm"
# define ESC_XPM "sprites/esc.xpm"

# define XPM_HEIGHT 64
# define XPM_WIDTH 64

typedef struct s_img
{
	void		*image;
	int			width;
	int			height;

}				t_img;

typedef struct s_matrix
{
	char		**map;
	int			total_item;
	size_t		htl;
	size_t		vtl;
}				t_matrix;

typedef struct s_data
{
	void		*xvar;
	void		*window;
	int			size_x;
	int			size_y;
	int			item_count;
	int			player_moves;
	t_matrix	matrix;
	t_img		wall;
	t_img		floor;
	t_img		item;
	t_img		cat_left;
	t_img		cat_right;
	t_img		cat_back;
	t_img		esc_final;
	t_img		esc;

}				t_data;

// so_long.c
int				main(int argc, char **argv);
int				check_argv(char *argv);

// utils
void			free_all(char **matrix);
void			print_error(void);
void			handle_img(t_data *data, int vtl, int htl);
void			put_img_to_window(t_data *data, t_img img, int vtl, int htl);
char			*dup_temp(const char *s1);

// closing_utils.c
int				handling_close(t_data *data);
int				handling_key(int key);
int				get_key(int key, void *param);
void			free_sprites(t_data *data);

// fill_map
char			**read_map(const char *file, t_matrix *matrix);

// check_items
int				parsing_map(t_matrix *matrix);

// check_map
int				check_rectangle(t_matrix *matrix);
int				check_walls(t_matrix *matrix);

// flood_fill
int				check_player_access(t_matrix *matrix);
int				final_check(t_matrix *matrix);

// init_game
void			initialize_window(t_data *data, t_matrix *matrix);
void			initialize_img(t_data *data, t_img *img);

// start_game
void			start_game(t_data *data);
void			play_game(t_data *data);
void			decide_path(t_data *data, int new_x, int new_y,
					t_img player_img);

#endif