/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:50:15 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:19 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	init_rays1 (t_all *ptr)
{
	ptr->camera_x = 2 * (ptr->r_w - ptr->x_iterator) / (double)ptr->r_w - 1;
	ptr->raydir_x = ptr->dir_x + ptr->plane_x * ptr->camera_x;
	ptr->raydir_y = ptr->dir_y + ptr->plane_y * ptr->camera_x;
}

void	init_rays2 (t_all *ptr)
{
	ptr->map_x = (int)ptr->x;
	ptr->map_y = (int)ptr->y;
	ptr->delta_dist_x = fabs(1 / ptr->raydir_x);
	ptr->delta_dist_y = fabs(1 / ptr->raydir_y);
}
