/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser6texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:53:41 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:09 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	process_texture1(char	*s, t_all *ptr)
{
	if (*s == 'N' && ptr->txtflag == 1)
		exit_error (17);
	else if (*s == 'E' && ptr->txtflag == 2)
		exit_error (17);
	else if (*s == 'S' && ptr->txtflag == 3)
		exit_error (17);
	else if (*s == 'W' && ptr->txtflag == 4)
		exit_error (17);
	else if (*s == 'S' && ptr->txtflag == 5)
		exit_error (17);
	if (*s == 'N' && *(s + 1) == 'O')
		ptr->txtflag = 1;
	else if (*s == 'E')
		ptr->txtflag = 2;
	else if (*s == 'S' && *(s + 1) == 'O')
		ptr->txtflag = 3;
	else if (*s == 'W')
		ptr->txtflag = 4;
	else if (*s == 'S' && *(s + 1) == ' ')
		ptr->txtflag = 5;
}

void	process_texture_flags(char	*saved, t_all *ptr)
{
	if (ptr->txtflag == 1)
		ptr->no = saved;
	else if (ptr->txtflag == 2)
		ptr->ea = saved;
	else if (ptr->txtflag == 3)
		ptr->so = saved;
	else if (ptr->txtflag == 4)
		ptr->we = saved;
	else if (ptr->txtflag == 5)
		ptr->s = saved;
}

char	*process_texture(char	*str, t_all *ptr)
{
	char	*savedstring;

	savedstring = NULL;
	process_texture1(str, ptr);
	if (ptr->no == 0 || ptr->ea == 0 || ptr->so == 0 || ptr->we == 0 || \
	 ptr->s == 0)
	{
		while (*str != '\0')
		{
			while (*str == ' ' && *(str + 1) != ' ')
			{
				savedstring = ft_strdup(++str);
				break ;
			}
			str++;
		}
	}
	else
		exit_error(7);
	process_texture_flags(savedstring, ptr);
	return (savedstring);
}

void	parse_texture_ns(char *str)
{
	if ((*str == 'N' && *(str + 1) == '\0') || \
	(*str == 'N' && *(str + 1) == 'O' && *(str + 2) == '\0') || \
	(*str == 'N' && *(str + 1) == 'O' && \
	((*(str + 2) >= 33 && *(str + 2) <= 64) || \
	(*(str + 2) >= 91 && *(str + 2) <= 127))) || \
	(*str == 'N' && ((*(str + 1) >= 33 && *(str + 1) <= 64) || \
	(*(str + 1) >= 91 && *(str + 1) <= 127))) || \
	(*str == ' ') || (*str == '/') || (*str == '.') || \
	(*str == 'N' && *(str + 1) == 'O' && *(str + 2) == 'O') || \
	(*str >= 32 && *str <= 64) || (*str >= 91 && *str <= 127))
		exit_error(8);
	else if ((*str == 'S' && *(str + 1) == '\0') || \
	(*str == 'S' && *(str + 1) == 'O' && *(str + 2) == '\0') || \
	(*str == 'S' && *(str + 1) == 'O' && ((*(str + 2) >= 33 && \
	 *(str + 2) <= 64) || (*(str + 2) >= 91 && *(str + 2) <= 127))) || \
	(*str == 'S' && ((*(str + 1) >= 33 && *(str + 1) <= 64))) || \
	(*(str + 1) >= 91 && *(str + 1) <= 127) || \
	(*str == 'S' && ((*(str + 1) >= 65 && *(str + 1) <= 78))) || \
	(*(str + 1) >= 80 && *(str + 1) <= 127) || \
	(*str == 'S' && *(str + 1) == 'O' && *(str + 2) == 'O'))
		exit_error(8);
}

void	parse_texture_we(char *str)
{
	if ((*str == 'W' && *(str + 1) == '\0') || \
	(*str == 'W' && *(str + 1) == 'E' && *(str + 2) == '\0') || \
	(*str == 'W' && *(str + 1) == 'E' && ((*(str + 2) >= 33 && \
	*(str + 2) <= 64) || (*(str + 2) >= 91 && *(str + 2) <= 127))) || \
	(*str == 'W' && ((*(str + 1) >= 33 && *(str + 1) <= 64) || \
	(*(str + 1) >= 91 && *(str + 1) <= 127))) || \
	(*str == ' ') || (*str == '/') || (*str == '.') || \
	(*str == 'W' && *(str + 1) == 'E' && *(str + 2) == 'E') || \
	(*str >= 32 && *str <= 64) || (*str >= 91 && *str <= 127))
		exit_error(8);
	else if ((*str == 'E' && *(str + 1) == '\0') || \
	(*str == 'E' && *(str + 1) == 'A' && *(str + 2) == '\0') || \
	(*str == 'E' && *(str + 1) == 'A' && ((*(str + 2) >= 33 && \
	*(str + 2) <= 64) || (*(str + 2) >= 91 && *(str + 2) <= 127))) || \
	(*str == 'E' && ((*(str + 1) >= 33 && *(str + 1) <= 64) || \
	(*(str + 1) >= 91 && *(str + 1) <= 127))) || \
	(*str == ' ') || (*str == '/') || (*str == '.') || \
	(*str == 'E' && *(str + 1) == 'A' && *(str + 2) == 'A') || \
	(*str >= 32 && *str <= 64) || (*str >= 91 && *str <= 127))
		exit_error(8);
}
