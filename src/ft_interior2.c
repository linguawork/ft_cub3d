/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interior2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:08:57 by areggie           #+#    #+#             */
/*   Updated: 2021/04/26 21:01:43 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	upload_texture (t_all *ptr, int qty, char *link)
{
	ptr->txr[qty]->img = mlx_xpm_file_to_image(ptr->wdw->mlx, \
	link, &ptr->txr[qty]->img_w, &ptr->txr[qty]->img_h);
	if (!(ptr->txr[qty]->img))
		exit_error(11);
	ptr->txr[qty]->addr = mlx_get_data_addr(ptr->txr[qty]->img, \
	&ptr->txr[qty]->bpp, &ptr->txr[qty]->size_line, &ptr->txr[qty]->end);
}

void	upload_texture_qty (t_all *ptr)
{
	upload_texture (ptr, 0, ptr->no);
	upload_texture (ptr, 1, ptr->so);
	upload_texture (ptr, 2, ptr->ea);
	upload_texture (ptr, 3, ptr->we);
	upload_texture (ptr, 4, ptr->s);
}
