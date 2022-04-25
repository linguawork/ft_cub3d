/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:38:08 by areggie           #+#    #+#             */
/*   Updated: 2021/04/23 22:11:52 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	bubble_sort_algo(int *seq, double *distance, t_all *ptr)
{
	int	i;
	int	j;
	int	d;
	int	s;

	i = -1;
	while (++i < ptr->spt_qty)
	{
		j = -1;
		while (++j < ptr->spt_qty - i - 1)
		{
			if (distance[j] > distance[j + 1])
			{
				s = seq[j];
				seq[j] = seq[j + 1];
				seq[j + 1] = s;
				d = distance[j];
				distance[j] = distance[j + 1];
				distance[j + 1] = d;
			}
		}
	}
}

void	farthest_to_nearest_sprite(t_all *ptr)
{
	int	itr;

	itr = 0;
	while (itr < ptr->spt_qty)
	{
		ptr->spt_sqc[itr] = itr;
		ptr->spt_dist[itr] = ((ptr->x - ptr->spt[itr]->sx) * \
		(ptr->x - ptr->spt[itr]->sx) + (ptr->y - ptr->spt[itr]->sy) * \
		(ptr->y - ptr->spt[itr]->sy));
		itr++;
	}
}

void	sorting_sprites (t_all *ptr)
{
	farthest_to_nearest_sprite(ptr);
	bubble_sort_algo(ptr->spt_sqc, ptr->spt_dist, ptr);
}

void	sprite_drawer (t_all *ptr)
{
	int	y;
	int	d;

	if (ptr->trf_y > 0 && ptr->sptline > 0 && \
	ptr->sptline < ptr->r_w && ptr->trf_y < ptr->zbuffer[ptr->sptline])
	{
		y = ptr->draws_y;
		while (y < ptr->drawe_y)
		{
			d = y * 256 - ptr->r_h * 128 + ptr->spt_height * 128;
			ptr->txre_y = ((d * ptr->txr[4]->img_h) / ptr->spt_height) / 256;
			ptr->color = ((int *)ptr->txr[4]->addr)[ptr->txr[4]->img_w * \
			ptr->txre_y + ptr->txre_x];
			if (ptr->color != 0x980088)
				my_mlx_pixel_put (ptr->wdw, ptr->sptline, y, ptr->color);
			y++;
		}
	}
}

void	sprite_put_together(t_all *ptr)
{
	int	i;

	i = ptr->spt_qty;
	sorting_sprites (ptr);
	while (--i >= 0)
	{
		if (ptr->spt_dist[i] > 0.2)
		{
			spt_pos_rel_to_cam (ptr, i);
			trans_inv_cam_mtx (ptr);
			calc_spt_height(ptr);
			calc_spt_bottom_top_pix (ptr);
			calc_spt_width (ptr);
			calc_spt_left_right_pix (ptr);
			while (ptr->sptline < ptr->drawe_x)
			{
				ptr->txre_x = (int)(256 * (ptr->sptline - (-(ptr->spt_width) / 2 \
				+ ptr->sptscr_x)) * ptr->txr[4]->img_w / ptr->spt_width) / 256;
				sprite_drawer(ptr);
				ptr->sptline++;
			}
		}
	}
}
