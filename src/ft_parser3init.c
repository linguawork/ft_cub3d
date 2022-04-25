/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser3init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:21:28 by areggie           #+#    #+#             */
/*   Updated: 2021/04/24 19:09:46 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	*arrays_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	go_out(void)
{
	exit(0);
	return (0);
}

int	exit_error(int err)
{
	exit_subfunction1(err);
	exit_subfunction2(err);
	exit_subfunction3(err);
	exit_subfunction4(err);
	exit_subfunction5(err);
	if (err == 21)
	{
		ft_putendl_fd("Error 21! Remove the comma after blue color int \n", 0);
		exit(1);
	}
	return (0);
}

void	init_struct(t_all *ptr)
{
	ptr->r_w = -1;
	ptr->r_h = -1;
	ptr->ceiling = -1;
	ptr->floor = -1;
	ptr->no = 0;
	ptr->ea = 0;
	ptr->so = 0;
	ptr->we = 0;
	ptr->s = 0;
	ptr->map = 0;
	ptr->height = 0;
	ptr->players_number = 0;
	ptr->spt_qty = 0;
	ptr->k_w = 0;
	ptr->k_s = 0;
	ptr->k_a = 0;
	ptr->k_d = 0;
	ptr->k_l = 0;
	ptr->k_r = 0;
	ptr->dir_x = -1;
	ptr->dir_y = 0;
	ptr->plane_x = 0;
	ptr->plane_y = 0.66;
	ptr->txtflag = 0;
	ptr->cfflag = 0;
}

t_all	*init_ptr(void)
{
	t_all		*ptr;

	ptr = (t_all *)malloc(sizeof(t_all) * 1);
	ptr->wdw = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	ptr->txr = (t_txr_win **)malloc(sizeof(t_txr_win) * 5);
	ptr->txr[0] = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	ptr->txr[1] = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	ptr->txr[2] = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	ptr->txr[3] = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	ptr->txr[4] = (t_txr_win *)malloc(sizeof(t_txr_win) * 1);
	init_struct(ptr);
	ptr->musflag = 0;
	ptr->screenshot_flag = 0;
	return (ptr);
}
