/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:34:40 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:02 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	arr_length(char **str)
{
	int	a;

	a = 0;
	while (*str)
	{
		str++;
		a++;
	}
	return (a);
}

void	process_char(char **s)
{
	char	*str;
	int		i;

	str = *s;
	i = 0;
	while (str[i] != '\0' )
	{	
		if (!(str[i] >= '0' && str[i] <= '9') && (!(str[i] == '\t')))
			exit_error(2);
		i++;
	}
}

void	process_char2(char **s2)
{
	char	*str;

	str = *s2;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9') && (*str != '\t') && (*str != ' '))
			exit_error(5);
		str++;
	}
}

void	process_commas(char **s2)
{
	char	*str;

	str = *s2;
	while (*str != '\0')
	{
		if (*str == ',' && *(str + 1) == ',')
		{
			exit_error(20);
		}
		str++;
	}
}
