/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:38:51 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:16 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	steps_xy (t_all *ptr)
{
	if (ptr->raydir_x < 0)
	{
		ptr->step_x = -1;
		ptr->sidedist_x = (ptr->x - ptr->map_x) * ptr->delta_dist_x;
	}
	else
	{
		ptr->step_x = 1;
		ptr->sidedist_x = (ptr->map_x + 1.0 - ptr->x) * ptr->delta_dist_x;
	}
	if (ptr->raydir_y < 0)
	{
		ptr->step_y = -1;
		ptr->sidedist_y = (ptr->y - ptr->map_y) * ptr->delta_dist_y;
	}
	else
	{
		ptr->step_y = 1;
		ptr->sidedist_y = (ptr->map_y + 1.0 - ptr->y) * ptr->delta_dist_y;
	}
}

void	perform_dda_algorithm (t_all *ptr)
{
	ptr->reach_wall = 0;
	while (ptr->reach_wall == 0)
	{
		if (ptr->sidedist_x < ptr->sidedist_y)
		{
			ptr->sidedist_x = ptr->sidedist_x + ptr->delta_dist_x;
			ptr->map_x = ptr->map_x + ptr->step_x;
			ptr->side = 0;
		}
		else
		{
			ptr->sidedist_y = ptr->sidedist_y + ptr->delta_dist_y;
			ptr->map_y = ptr->map_y + ptr->step_y;
			ptr->side = 1;
		}
		if (ptr->map[ptr->map_y][ptr->map_x] == '1')
			ptr->reach_wall = 1;
	}
}

void	process_distance_to_wall (t_all *ptr)
{
	if (ptr->side == 0)
		ptr->perp_wall_dist = (ptr->map_x - ptr->x + (1 - ptr->step_x) / 2) / \
		ptr->raydir_x;
	else
		ptr->perp_wall_dist = (ptr->map_y - ptr->y + (1 - ptr->step_y) / 2) / \
		ptr->raydir_y;
}

void	draw_stripe(t_all *ptr)
{
	ptr->stripeheight = (int)(ptr->r_h / ptr->perp_wall_dist);
	ptr->draw_start = -ptr->stripeheight / 2 + ptr->r_h / 2;
	if (ptr->draw_start < 0)
		ptr->draw_start = 0;
	ptr->draw_end = ptr->stripeheight / 2 + ptr->r_h / 2;
	if (ptr->draw_end >= ptr->r_h)
		ptr->draw_end = ptr->r_h - 1;
}

void	raycasting (t_all *ptr)
{
	ptr->x_iterator = 0;
	while (ptr->x_iterator < ptr->r_w)
	{
		init_rays1(ptr);
		init_rays2(ptr);
		steps_xy(ptr);
		perform_dda_algorithm(ptr);
		process_distance_to_wall(ptr);
		draw_stripe(ptr);
		where_wall_was_hit(ptr);
		upload_ceiling_wall_floor(ptr);
		ptr->x_iterator++;
	}
	sprite_put_together(ptr);
}
