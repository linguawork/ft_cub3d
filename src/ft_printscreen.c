/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printscreen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:41:30 by areggie           #+#    #+#             */
/*   Updated: 2021/04/20 22:11:13 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cube3d.h"

void	f_header(t_all *ptr, int fd)
{
	unsigned char	*f_header;
	int				file_size;

	f_header = ft_calloc(14, sizeof(unsigned char));
	if (!(f_header))
		exit(0);
	file_size = 14 + 40 + ptr->wdw->bpp / 8 * ptr->r_w * ptr->r_h;
	f_header[0] = (unsigned char)('B');
	f_header[1] = (unsigned char)('M');
	f_header[2] = (unsigned char)(file_size);
	f_header[3] = (unsigned char)(file_size >> 8);
	f_header[4] = (unsigned char)(file_size >> 16);
	f_header[5] = (unsigned char)(file_size >> 24);
	f_header[10] = (unsigned char)(14 + 40);
	write(fd, f_header, 14);
	free(f_header);
}

void	i_header(t_all *ptr, int fd)
{
	unsigned char	*i_header;

	i_header = ft_calloc(40, sizeof(unsigned char));
	if (!(i_header))
		exit(0);
	i_header[0] = (unsigned char)(40);
	i_header[4] = (unsigned char)(ptr->r_w);
	i_header[5] = (unsigned char)(ptr->r_w >> 8);
	i_header[6] = (unsigned char)(ptr->r_w >> 16);
	i_header[7] = (unsigned char)(ptr->r_w >> 24);
	i_header[8] = (unsigned char)(ptr->r_h);
	i_header[9] = (unsigned char)(ptr->r_h >> 8);
	i_header[10] = (unsigned char)(ptr->r_h >> 16);
	i_header[11] = (unsigned char)(ptr->r_h >> 24);
	i_header[12] = (unsigned char)(1);
	i_header[14] = (unsigned char)(ptr->wdw->bpp);
	write(fd, i_header, 40);
	free(i_header);
}

int	shoot_image(t_all *ptr, char *pic_name)
{
	int	h;
	int	w;
	int	fd;
	int	color;

	fd = open(pic_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!(fd))
		exit_error(16);
	f_header(ptr, fd);
	i_header(ptr, fd);
	h = ptr->r_h;
	while (h--)
	{
		w = 0;
		while (w < ptr->r_w)
		{
			color = ((int *)ptr->wdw->addr)[h * ptr->wdw->size_line / 4 + w];
			write(fd, &color, 4);
			w++;
		}
	}
	printf("\nBMP file saved");
	return (fd);
}

void	print_bmp_file(t_all *ptr)
{
	int	fd;

	ptr->wdw->mlx = mlx_init();
	ptr->wdw->img = mlx_new_image(ptr->wdw->mlx, ptr->r_w, ptr->r_h);
	ptr->wdw->addr = mlx_get_data_addr(ptr->wdw->img, &ptr->wdw->bpp, \
	&ptr->wdw->size_line, &ptr->wdw->end);
	upload_texture_qty(ptr);
	raycasting(ptr);
	fd = shoot_image(ptr, "screenshot.bmp");
	close(fd);
}
