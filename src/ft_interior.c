/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interior.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:18:04 by areggie           #+#    #+#             */
/*   Updated: 2021/04/26 20:57:58 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	where_wall_was_hit(t_all *ptr)
{
	if (ptr->side == 0)
		ptr->wallx = ptr->y + ptr->perp_wall_dist * ptr->raydir_y;
	else
		ptr->wallx = ptr->x + ptr->perp_wall_dist * ptr->raydir_x;
	ptr->wallx = ptr->wallx - floor(ptr->wallx);
}

void	my_mlx_pixel_put( t_txr_win *wdw, int x, int y, int color)
{
	char	*dst;

	dst = wdw->addr + (y * wdw->size_line + x * (wdw->bpp / 8));
	*(unsigned int *)dst = color;
}

void	analyze_texture(t_all *ptr, int txre_height, int txre_width, void *addr)
{
	int	y;
	int	color;

	ptr->txre_x = (int)(ptr->wallx * (double)txre_width);
	if (ptr->side == 0 && ptr->raydir_x > 0)
		ptr->txre_x = txre_width - ptr->txre_x - 1;
	if (ptr->side == 1 && ptr->raydir_y < 0)
		ptr->txre_x = txre_width - ptr->txre_x - 1;
	ptr->step = 1.0 * txre_height / ptr->stripeheight;
	ptr->tex_pos = (ptr->draw_start - ptr->r_h / 2 + ptr->stripeheight / 2) \
	* ptr->step;
	y = ptr->draw_start;
	while (y < ptr->draw_end)
	{
		ptr->txre_y = (int)ptr->tex_pos & (txre_height - 1);
		ptr->tex_pos = ptr->tex_pos + ptr->step;
		color = ((int *)addr)[txre_height * ptr->txre_y + ptr->txre_x];
		my_mlx_pixel_put(ptr->wdw, ptr->x_iterator, y, color);
		y++;
	}
}

void	upload_ceiling_floor (t_all *ptr)
{
	int	y;
	int	x;

	x = ptr->start;
	y = ptr->end;
	ptr->start = 0;
	ptr->end = ptr->draw_end;
	while (x < ptr->draw_start)
	{
		my_mlx_pixel_put(ptr->wdw, ptr->x_iterator, x, ptr->ceiling);
		x++;
	}
	while (y < ptr->r_h)
	{
		my_mlx_pixel_put(ptr->wdw, ptr->x_iterator, y, ptr->floor);
		y++;
	}
}

void	upload_ceiling_wall_floor(t_all *ptr)
{
	if (ptr->side == 1)
	{
		if (ptr->step_y > 0)
			analyze_texture(ptr, ptr->txr[0]->img_h, ptr->txr[0]->img_w, \
			ptr->txr[1]->addr);
		if (ptr->step_y < 0)
			analyze_texture(ptr, ptr->txr[1]->img_h, ptr->txr[1]->img_w, \
			ptr->txr[0]->addr);
	}
	if (ptr->side == 0)
	{
		if (ptr->step_x > 0)
			analyze_texture(ptr, ptr->txr[3]->img_h, ptr->txr[3]->img_w, \
			ptr->txr[3]->addr);
		if (ptr->step_x < 0)
			analyze_texture(ptr, ptr->txr[2]->img_h, ptr->txr[2]->img_w, \
			ptr->txr[2]->addr);
	}
	ptr->zbuffer[ptr->x_iterator] = ptr->perp_wall_dist;
	upload_ceiling_floor(ptr);
}
