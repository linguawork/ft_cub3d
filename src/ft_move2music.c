/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2music.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:38:52 by areggie           #+#    #+#             */
/*   Updated: 2021/04/26 22:51:12 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	key_on2(int key)
{
	if (key == 53)
	{	
		exit(0);
	}
	return (0);
}

int	key_on (int key, t_all *ptr)
{
	if (key == 13)
		ptr->k_w = 1;
	if (key == 1)
		ptr->k_s = 1;
	if (key == 0)
		ptr->k_a = 1;
	if (key == 2)
		ptr->k_d = 1;
	if (key == 123)
		ptr->k_l = 1;
	if (key == 124)
		ptr->k_r = 1;
	key_on2(key);
	return (0);
}

int	key_off (int key, t_all *ptr)
{
	if (key == 13)
		ptr->k_w = 0;
	if (key == 1)
		ptr->k_s = 0;
	if (key == 0)
		ptr->k_a = 0;
	if (key == 2)
		ptr->k_d = 0;
	if (key == 123)
		ptr->k_l = 0;
	if (key == 124)
		ptr->k_r = 0;
	return (0);
}
