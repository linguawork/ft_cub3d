/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:20:26 by areggie           #+#    #+#             */
/*   Updated: 2021/04/21 21:25:24 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	process_resolution(char *str, t_all *ptr)
{
	char	**arr;
	int		len;

	if (ptr->r_w != -1 || ptr->r_h != -1)
		exit_error(6);
	arr = ft_split(str, ' ');
	len = arr_length(arr);
	if (len == 3)
	{	
		ptr->r_w = ft_atoi(arr[1]);
		process_char(&arr[1]);
		ptr->r_h = ft_atoi(arr[2]);
		process_char(&arr[2]);
	}
	else
		exit_error(1);
	if (ptr->r_w < 1 || ptr->r_h < 1)
		exit_error (2);
	if (ptr->r_w > 2000)
		ptr->r_w = 2000;
	if (ptr->r_w < 80)
		ptr->r_w = 80;
	ptr->r_h = (ptr->r_w / 2);
	ptr->zbuffer = ft_calloc(sizeof(double), ptr->r_w + 1);
	arrays_free(arr);
}

void	process_color3(t_all *ptr, int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		exit_error (5);
	else
	{
		if (ptr->cfflag == 1)
			ptr->ceiling = r << 16 | g << 8 | b;
		if (ptr->cfflag == 2)
			ptr->floor = r * 65536 + g * 256 + b;
	}
}

void	process_color2(t_all *ptr, int length, char **str)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	if (length == 3)
	{
		r = ft_atoi(str[0]);
		process_char2(&str[0]);
		g = ft_atoi(str[1]);
		process_char2(&str[1]);
		b = ft_atoi(str[2]);
		process_char2(&str[2]);
	}
	else
		exit_error(4);
	process_color3(ptr, r, g, b);
}

void	process_color(t_all *ptr, char *str)
{
	char	**c_array;
	int		len;

	if (*str == 'C' && ptr->ceiling != -1)
		exit_error (6);
	else if (*str == 'F' && ptr->floor != -1)
		exit_error (19);
	process_commas(&str);
	if (*str == 'C')
	{
		str++;
		ptr->cfflag = 1;
	}
	if (*str == 'F')
	{
		str++;
		ptr->cfflag = 2;
	}
	c_array = ft_split(str, ',');
	len = arr_length(c_array);
	process_color2(ptr, len, c_array);
	arrays_free(c_array);
}
