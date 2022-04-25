/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:50:59 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:21 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	sprite_finder(t_all *ptr)
{
	int	x;
	int	y;
	int	spt_counter;

	x = 0;
	spt_counter = 0;
	while (ptr->map[x])
	{
		y = 0;
		while (ptr->map[x][y])
		{
			if (ptr->map[x][y] == '2')
			{
				if (spt_counter < ptr->spt_qty)
				{
					ptr->spt[spt_counter]->sx = y + 0.5;
					ptr->spt[spt_counter]->sy = x + 0.5;
					spt_counter++;
				}
			}
			y++;
		}
		x++;
	}
}

int	initialize_sprites (t_all *ptr)
{
	int	itr;

	ptr->spt = (t_spt **)ft_calloc(sizeof(t_spt *), ptr->spt_qty + 1);
	if (!(ptr->spt))
		return (0);
	itr = 0;
	while (itr < ptr->spt_qty)
	{
		ptr->spt[itr] = (t_spt *)ft_calloc(sizeof(t_spt), 1);
		if (!(ptr->spt[itr]))
			return (0);
		itr++;
	}
	sprite_finder(ptr);
	return (0);
}

void	process_sprites(t_all *ptr)
{
	int	x;
	int	y;

	x = 0;
	while (ptr->map[x])
	{
		y = 0;
		while (ptr->map[x][y] != '\0')
		{
			if (ptr->map[x][y] == '2')
				ptr->spt_qty = ptr->spt_qty + 1;
			y++;
		}
		x++;
	}
	initialize_sprites(ptr);
	ptr->spt_sqc = (int *)ft_calloc(sizeof(int), ptr->spt_qty + 1);
	ptr->spt_dist = (double *)ft_calloc(sizeof(double), ptr->spt_qty + 1);
}
