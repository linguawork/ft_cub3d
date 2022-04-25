/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:10:18 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:31 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	trans_inv_cam_mtx (t_all *ptr)
{
	ptr->inv = 1.0 / (ptr->plane_x * ptr->dir_y - ptr->dir_x * ptr->plane_y);
	ptr->trf_x = ptr->inv * (ptr->dir_y * ptr->spt_x - ptr->dir_x * ptr->spt_y);
	ptr->trf_y = ptr->inv * (-ptr->plane_y * ptr->spt_x + ptr->plane_x * \
	ptr->spt_y);
	ptr->sptscr_x = (int)(ptr->r_w - ptr->r_w / 2 * (1 + ptr->trf_x / \
	ptr->trf_y));
}

void	calc_spt_height(t_all *ptr)
{
	ptr->spt_height = abs((int)(ptr->r_h / (ptr->trf_y)));
}

void	calc_spt_bottom_top_pix (t_all *ptr)
{
	ptr->draws_y = -ptr->spt_height / 2 + ptr->r_h / 2;
	if (ptr->draws_y < 0)
		ptr->draws_y = 0;
	ptr->drawe_y = ptr->spt_height / 2 + ptr->r_h / 2;
	if (ptr->drawe_y >= ptr->r_h)
		ptr->drawe_y = ptr->r_h - 1;
}

void	calc_spt_width (t_all *ptr)
{
	ptr->spt_width = abs((int)(ptr->r_h / (ptr->trf_y)));
}

void	calc_spt_left_right_pix (t_all *ptr)
{
	ptr->draws_x = (-ptr->spt_width) / 2 + ptr->sptscr_x;
	if (ptr->draws_x < 0)
		ptr->draws_x = 0;
	ptr->drawe_x = ptr->spt_width / 2 + ptr->sptscr_x;
	if (ptr->drawe_x >= ptr->r_w)
		ptr->drawe_x = ptr->r_w - 1;
	ptr->sptline = ptr->draws_x;
}
