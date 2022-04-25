/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validator2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:40:50 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:10:35 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	player_sight_angle(char c, t_all *ptr)
{
	if (c == 'N')
	{
		ptr->dir_x = 0;
		ptr->dir_y = -1;
		ptr->plane_x = -0.66;
		ptr->plane_y = 0;
	}
	if (c == 'E')
	{
		ptr->dir_x = 1;
		ptr->dir_y = 0;
		ptr->plane_x = 0;
		ptr->plane_y = -0.66;
	}
	if (c == 'S')
	{
		ptr->dir_x = 0;
		ptr->dir_y = 1;
		ptr->plane_x = 0.66;
		ptr->plane_y = 0;
	}
}
