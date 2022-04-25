/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:35:38 by areggie           #+#    #+#             */
/*   Updated: 2021/04/26 22:04:20 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	forwards_backwards(t_all *ptr)
{
	if (ptr->k_w)
	{
		if (ptr->map[(int)(ptr->y)][(int)(ptr->x + ptr->dir_x * ptr->m_speed)]
			!= '1')
			ptr->x = ptr->x + ptr->dir_x * ptr->m_speed;
		if (ptr->map[(int)(ptr->y + ptr->dir_y * ptr->m_speed)][(int)(ptr->x)]
			!= '1')
			ptr->y = ptr->y + ptr->dir_y * ptr->m_speed;
	}
	if (ptr->k_s)
	{
		if (ptr->map[(int)(ptr->y)][(int)(ptr->x - ptr->dir_x * ptr->m_speed)]
			!= '1')
			ptr->x = ptr->x - ptr->dir_x * ptr->m_speed;
		if (ptr->map[(int)(ptr->y - ptr->dir_y * ptr->m_speed)][(int)(ptr->x)]
			!= '1')
			ptr->y = ptr->y - ptr->dir_y * ptr->m_speed;
	}
}

void	step_left_right(t_all *ptr)
{
	if (ptr->k_a)
	{
		if (ptr->map[(int)(ptr->y)][(int)(ptr->x + ptr->plane_x * ptr->m_speed)]
			!= '1')
			ptr->x = ptr->x + ptr->plane_x * ptr->m_speed;
		if (ptr->map[(int)(ptr->y + ptr->plane_y * ptr->m_speed)][(int)(ptr->x)]
			!= '1')
			ptr->y = ptr->y + ptr->plane_y * ptr->m_speed;
	}
	if (ptr->k_d)
	{
		if (ptr->map[(int)(ptr->y)][(int)(ptr->x - ptr->plane_x * ptr->m_speed)]
			!= '1')
			ptr->x = ptr->x - ptr->plane_x * ptr->m_speed;
		if (ptr->map[(int)(ptr->y - ptr->plane_y * ptr->m_speed)][(int)(ptr->x)]
			!= '1')
			ptr->y = ptr->y - ptr->plane_y * ptr->m_speed;
	}	
}

void 	rotate_right(t_all *ptr)
{
	if (ptr->k_r)
	{
		ptr->olddir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(ptr->r_speed) - ptr->dir_y * \
		sin(ptr->r_speed);
		ptr->dir_y = ptr->olddir_x * sin(ptr->r_speed) + ptr->dir_y * \
		cos(ptr->r_speed);
		ptr->oldplane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(ptr->r_speed) - ptr->plane_y * \
		(ptr->r_speed);
		ptr->plane_y = ptr->oldplane_x * sin (ptr->r_speed) + ptr->plane_y * \
		cos (ptr->r_speed);
	}
}

void	rotate_left(t_all *ptr)
{
	if (ptr->k_l)
	{
		ptr->olddir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(-(ptr->r_speed)) - ptr->dir_y * \
		sin(-(ptr->r_speed));
		ptr->dir_y = ptr->olddir_x * sin(-(ptr->r_speed)) + ptr->dir_y * \
		cos(-(ptr->r_speed));
		ptr->oldplane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(-(ptr->r_speed)) - ptr->plane_y * \
		(-(ptr->r_speed));
		ptr->plane_y = ptr->oldplane_x * sin (-(ptr->r_speed)) + \
		ptr->plane_y * cos (-(ptr->r_speed));
	}
}

int	process_keys (t_all *ptr)
{
	ptr->m_speed = 0.1;
	ptr->r_speed = 0.10;
	forwards_backwards(ptr);
	step_left_right(ptr);
	rotate_left(ptr);
	rotate_right(ptr);
	return (0);
}
