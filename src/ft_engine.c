/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:33:58 by areggie           #+#    #+#             */
/*   Updated: 2021/04/26 22:08:46 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

int	step_and_ray(t_all *ptr)
{
	raycasting(ptr);
	process_keys(ptr);
	mlx_put_image_to_window(ptr->wdw->mlx, ptr->wdw->win, ptr->wdw->img, 0, 0);
	mlx_do_sync(ptr->wdw->mlx);
	return (0);
}

void	mlx_put_together(t_all *ptr)
{
	ptr->wdw->mlx = mlx_init();
	ptr->wdw->win = mlx_new_window(ptr->wdw->mlx, ptr->r_w, ptr->r_h, \
	"Cube3D");
	ptr->wdw->img = mlx_new_image(ptr->wdw->mlx, ptr->r_w, ptr->r_h);
	ptr->wdw->addr = mlx_get_data_addr(ptr->wdw->img, &ptr->wdw->bpp, \
	&ptr->wdw->size_line, &ptr->wdw->end);
	upload_texture_qty(ptr);
	mlx_hook(ptr->wdw->win, 2, (1L << 0), &key_on, ptr);
	mlx_hook(ptr->wdw->win, 3, (1L << 0), &key_off, ptr);
	mlx_hook(ptr->wdw->win, 17, (1L << 0), &go_out, NULL);
	mlx_loop_hook (ptr->wdw->mlx, &step_and_ray, ptr);
	mlx_loop(ptr->wdw->mlx);
}

int	check_argv_name(char *argvname)
{
	int	len;

	len = ft_strlen (argvname);
	if (len >= 4)
	{
		argvname = argvname + len - 4;
		if (ft_strncmp(argvname, ".cub", 4 ) == 0)
			return (1);
	}
	return (0);
}

void	main_function_part(int argc, char **argv, t_all *ptr, int file_d)
{
	file_d = open(argv[1], O_RDONLY);
	if (argc < 2 || argc > 3)
		exit_error(12);
	else if (!(check_argv_name(argv[1])) || (file_d < 0))
		exit_error(13);
	else if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) == 0))
		ptr->screenshot_flag = 1;
	else if (argc == 3)
		exit_error(14);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_list	*head;
	t_all	*ptr;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	ptr = init_ptr();
	main_function_part(argc, argv, ptr, fd);
	if (argc <= 3 && argc >= 2)
	{
		while (get_next_line(fd, &line))
			ft_lstadd_back(&head, ft_lstnew(line));
		ft_lstadd_back(&head, ft_lstnew(line));
		read_mapfile(ptr, &head);
		if (ptr->screenshot_flag == 1)
			print_bmp_file(ptr);
		else
			mlx_put_together(ptr);
	}
	else
		exit_error(12);
	return (0);
}
