/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:15:37 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:14:52 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	spt_pos_rel_to_cam (t_all *ptr, int num)
{
	ptr->spt_x = ptr->spt[ptr->spt_sqc[num]]->sx - ptr->x;
	ptr->spt_y = ptr->spt[ptr->spt_sqc[num]]->sy - ptr->y;
	num++;
}
