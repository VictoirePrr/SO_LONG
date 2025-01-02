/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:31:35 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/18 14:57:47 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_window(t_data *data, t_matrix *matrix)
{
	data->xvar = mlx_init();
	if (!data->xvar)
	{
		print_mess("The project couldn't be initialized !");
		free(data->xvar);
	}
	data->window = mlx_new_window(data->xvar, XPM_HEIGHT * (matrix->htl),
			XPM_WIDTH * (matrix->vtl), "hungry_kitty");
	if (!data->window)
	{
		print_mess("The window couldn't be initialized !");
		free(data->window);
	}
	print_mess("Window initialized...\n");
}

t_img	put_xpm_to_data(void *xvar, char *xpm, t_img *img)
{
	img->width = XPM_WIDTH;
	img->height = XPM_HEIGHT;
	img->image = mlx_xpm_file_to_image(xvar, xpm, &img->width, &img->height);
	if (!img->image)
	{
		print_mess("The image couldn't be initialized !");
		free(img->image);
	}
	return (*img);
}
void	initialize_img(t_data *data, t_img *img)
{
	void	*xvar;

	xvar = data->xvar;
	data->wall = put_xpm_to_data(xvar, WALL_XPM, img);
	data->floor = put_xpm_to_data(xvar, FLOOR_XPM, img);
	data->item = put_xpm_to_data(xvar, ITEM_XPM, img);
	data->cat_left = put_xpm_to_data(xvar, CAT_LEFT_XPM, img);
	data->cat_right = put_xpm_to_data(xvar, CAT_RIGHT_XPM, img);
	data->cat_back = put_xpm_to_data(xvar, CAT_BACK_XPM, img);
	data->esc_final = put_xpm_to_data(xvar, ESC_FINAL_XPM, img);
	data->esc = put_xpm_to_data(xvar, ESC_XPM, img);
	print_mess("Images charging...\n");
}
