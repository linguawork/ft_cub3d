/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:39:45 by areggie           #+#    #+#             */
/*   Updated: 2021/04/23 22:00:41 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	parse_given_map(char *str, t_all *ptr)
{
	if (*str == 'R' && *(str + 1) == ' ')
		process_resolution(str, ptr);
	else if ((ptr->cfflag == 1) && (ptr->cfflag == 2))
		exit_error(6);
	else if ((*str == 'C' && *(str + 1) == '\0') || \
	(*str == 'C' && ((*(str + 1) >= 33 && *(str + 1) <= 64) || \
	(*(str + 1) >= 91 && *(str + 1) <= 127))) || \
	(*str >= 33 && *str <= 64) || (*str >= 91 && *str <= 127))
		exit_error(6);
	else if ((*str == 'C' && *(str + 1) == ' ') || \
	(*str == 'F' && *(str + 1) == ' '))
		process_color(ptr, str);
	parse_texture_ns(str);
	parse_texture_we(str);
	if ((*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ') || \
	(*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ') || \
	(*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ') || \
	(*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ') || \
	(*str == 'S' && *(str + 1) == ' ' ))
		process_texture(str, ptr);
	free (str);
}

int	map_structure_allsaved(t_all *ptr)
{
	if (ptr->r_w != -1 && ptr->r_h != -1 && ptr->ceiling != -1 && ptr->floor != -1 && ptr->no != 0 && ptr->ea != 0 && ptr->so != 0 \
	&& ptr->we != 0 && ptr->s != 0)
		return (1);
	else
		return (0);
}

void	make_map(t_list *temp, t_all *ptr)
{
	int	i;

	ptr->map = ft_calloc(ft_lstsize(temp) + 1, sizeof(char *));
	i = -1;
	while (temp)
	{
		ptr->map[++i] = temp->content;
		temp = temp->next;
	}	
}

void	read_mapfile(t_all *ptr, t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp)
	{
		if (map_structure_allsaved(ptr))
		{
			make_map(temp, ptr);
			break ;
		}
		else
			parse_given_map(temp->content, ptr);
		if (temp->next == NULL && !(map_structure_allsaved(ptr)))
			exit_error(8);
		temp = temp->next;
	}
	map_validator(ptr);
}
