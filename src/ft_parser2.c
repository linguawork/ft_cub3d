/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:52:17 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:10:53 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	exit_subfunction1(int err)
{
	if (err == 1)
	{
		ft_putendl_fd("Error 1! Please, correct resolution\n", 0);
		exit(1);
	}
	else if (err == 2)
	{
		ft_putendl_fd("Error 2! Please, correct resolution\n", 0);
		exit(1);
	}
	else if (err == 3)
	{
		ft_putendl_fd(" Error 3! Invalid map\n", 0);
		exit(1);
	}
	else if (err == 4)
	{
		ft_putendl_fd(" Error 4! Incorrect number of color argument\n", 0);
		exit(1);
	}
	return (0);
}

int	exit_subfunction2(int err)
{
	if (err == 5)
	{
		ft_putendl_fd("Error 5! Invalid color input\n", 0);
		exit(1);
	}
	else if (err == 6)
	{
		ft_putendl_fd("Error 6! Wrong input value\n", 0);
		exit(1);
	}
	else if (err == 7)
	{
		ft_putendl_fd("Error 7! Textures have got values already\n", 0);
		exit(1);
	}
	else if (err == 8)
	{
		ft_putendl_fd("Error 8! Not all parameters saved to structure\n", 0);
		exit(1);
	}
	return (0);
}

int	exit_subfunction3(int err)
{
	if (err == 9)
	{
		ft_putendl_fd("Error 9! Invalid map\n", 0);
		exit(1);
	}
	else if (err == 10)
	{
		ft_putendl_fd("Error 10! More than 1 player\n", 0);
		exit(1);
	}
	else if (err == 11)
	{
		ft_putendl_fd("Error 11! No texture image\n", 0);
		exit(1);
	}
	else if (err == 12)
	{
		ft_putendl_fd("Error 12! Incorrect number of arguments\n", 0);
		exit(1);
	}
	return (0);
}

int	exit_subfunction4(int err)
{
	if (err == 13)
	{
		ft_putendl_fd("Error 13! Incorrect map name\n", 0);
		exit(1);
	}
	else if (err == 14)
	{
		ft_putendl_fd("Error 14! The second argument is incorrect\n", 0);
		exit(1);
	}
	else if (err == 15)
	{
		ft_putendl_fd("Error 15! There is no player in the map\n", 0);
		exit(1);
	}
	else if (err == 16)
	{
		ft_putendl_fd("Error 16! Could not create a bmp file\n", 0);
		exit(1);
	}
	return (0);
}

int	exit_subfunction5(int err)
{
	if (err == 17)
	{
		ft_putendl_fd("Error 17! Repeated path to a texture\n", 0);
		exit(1);
	}
	else if (err == 18)
	{
		ft_putendl_fd("Error 18! Resolution has got value already\n", 0);
		exit(1);
	}	
	else if (err == 19)
	{
		ft_putendl_fd("Error 19! F has got value already\n", 0);
		exit(1);
	}
	else if (err == 20)
	{
		ft_putendl_fd("Error 20! Two consecutive commas \n", 0);
		exit(1);
	}
	return (0);
}
