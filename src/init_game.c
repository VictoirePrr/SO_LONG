/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:31:35 by vicperri          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:09 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_window(t_data *data, t_matrix *matrix)
{
	data->xvar = mlx_init();
	if (!data->xvar)
	{
		ft_printf("The project couldn't be initialized !");
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->xvar, XPM_HEIGHT * (matrix->htl),
			XPM_WIDTH * (matrix->vtl), "hungry_kitty");
	if (!data->window)
	{
		ft_printf("The window couldn't be initialized !");
		mlx_destroy_display(data->xvar);
		free(data->xvar);
		exit(EXIT_FAILURE);
	}
	ft_printf("Window initialized...\n");
}

t_img	put_xpm_to_data(void *xvar, char *xpm, t_img *img)
{
	img->width = XPM_WIDTH;
	img->height = XPM_HEIGHT;
	img->image = mlx_xpm_file_to_image(xvar, xpm, &img->width, &img->height);
	if (!img->image)
	{
		ft_printf("The image couldn't be initialized !\n");
		free(img->image);
	}
	return (*img);
}

void	img_to_null(t_data *data)
{
	data->wall.image = NULL;
	data->floor.image = NULL;
	data->item.image = NULL;
	data->cat_left.image = NULL;
	data->cat_right.image = NULL;
	data->cat_back.image = NULL;
	data->esc_final.image = NULL;
	data->esc.image = NULL;
}

void	initialize_img_part_one(t_data *data, t_img *img)
{
	void	*xvar;

	xvar = data->xvar;
	data->wall = put_xpm_to_data(xvar, WALL_XPM, img);
	ft_printf("Downloading wall...\n");
	if (!(data->wall.image))
		handling_close(data);
	data->floor = put_xpm_to_data(xvar, FLOOR_XPM, img);
	ft_printf("Downloading floor...\n");
	if (!(data->floor.image))
		handling_close(data);
	data->item = put_xpm_to_data(xvar, ITEM_XPM, img);
	ft_printf("Downloading strawberry...\n");
	if (!(data->item.image))
		handling_close(data);
	data->cat_left = put_xpm_to_data(xvar, CAT_LEFT_XPM, img);
	if (!(data->cat_left.image))
		handling_close(data);
}

void	initialize_img_part_two(t_data *data, t_img *img)
{
	void	*xvar;

	xvar = data->xvar;
	data->cat_right = put_xpm_to_data(xvar, CAT_RIGHT_XPM, img);
	if (!(data->cat_right.image))
		handling_close(data);
	data->cat_back = put_xpm_to_data(xvar, CAT_BACK_XPM, img);
	ft_printf("Downloading kitty...\n");
	if (!(data->cat_back.image))
		handling_close(data);
	data->esc_final = put_xpm_to_data(xvar, ESC_FINAL_XPM, img);
	if (!(data->esc_final.image))
		handling_close(data);
	data->esc = put_xpm_to_data(xvar, ESC_XPM, img);
	ft_printf("Downloading box...\n");
	if (!(data->esc.image))
		handling_close(data);
}
