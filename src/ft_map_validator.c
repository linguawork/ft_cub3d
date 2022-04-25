/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:40:38 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:10:32 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	check_map_height(t_all *ptr)
{
	int	i;

	i = 0;
	while (ptr->map[i])
		i++;
	return (i);
}

void	check_player(t_all *ptr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	ptr->height = check_map_height(ptr);
	while (++i < (size_t)ptr->height)
	{
		j = -1;
		k = ft_strlen(ptr->map[i]);
		while (++j < k)
		{
			if (ft_strchr ("NESW", ptr->map [i][j]))
			{
				ptr->players_number++;
				ptr->x = j + 0.5;
				ptr->y = i + 0.5;
				player_sight_angle(ptr->map [i][j], ptr);
			}
			if (!ft_strchr ("120NESW ", ptr->map [i][j]))
				exit_error(9);
		}
	}
}

int	cross_check(char **map, size_t i, size_t j)
{
	if (map[i + 1][j] == ' ' || map [i][j + 1] == ' ' || \
		map[i - 1][j] == ' ' || map [i][j - 1] == ' ' || \
		map[i + 1][j + 1] == ' ' || map [i + 1][j - 1] == ' ' || \
		map[i - 1][j - 1] == ' ' || map [i - 1][j + 1] == ' ' || \
		map[i + 1][j] == '\0' || map [i][j + 1] == '\0' || \
		map[i - 1][j] == '\0' || map [i][j - 1] == '\0' || \
		map[i + 1][j + 1] == '\0' || map [i - 1][j + 1] == '\0')
		return (0);
	return (1);
}

void	check_around(t_all *ptr)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	ptr->height = check_map_height(ptr);
	while (i < (size_t)ptr->height)
	{
		j = 0;
		k = ft_strlen(ptr->map[i]);
		while (j < k)
		{
			if (ft_strchr ("NESW20", ptr->map [i][j]))
			{
				if (j == k - 1 || i == 0 || j == 0 || \
				i == (size_t)ptr->height - 1)
					exit_error(9);
				if (!cross_check (ptr->map, i, j))
					exit_error(9);
			}
			j++;
		}
		i++;
	}
}

void	map_validator(t_all *ptr)
{
	check_around(ptr);
	check_player(ptr);
	process_sprites(ptr);
	if (ptr->players_number > 1)
		exit_error(10);
	if (ptr->players_number == 0)
		exit_error(15);
}
