/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2music_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:38:52 by areggie           #+#    #+#             */
/*   Updated: 2021/04/25 20:17:46 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	key_on2(int key, t_all *ptr)
{
	if (key == 53)
	{	
		system("afplay hasta.mp3 &");
		sleep(2);
		system("killall afplay");
		exit(0);
	}
	if (ptr->musflag == 0 && key == 6)
	{
		ptr->musflag = 1;
		system("afplay raise.mp3 &");
		system("afplay term.mp3 &");
	}
	if (key == 7)
	{
		ptr->musflag = 0;
		system("killall afplay");
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
	if (ptr->k_a == 1 && ptr->k_s == 1)
		system("afplay iback.mp3 &");
	if (ptr->k_s == 1 && ptr->k_d == 1)
		system("afplay noproblemo.mp3 &");
	if (ptr->k_l == 1 && ptr->k_r == 1)
		system("afplay sheback.mp3 &");
	key_on2(key, ptr);
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
