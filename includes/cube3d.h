#ifndef CUBE3D_H
# define CUBE3D_H

# include "./../libft/libft.h"
# include <stdio.h>
# include "./../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_texture
{
	void	*mlx;
	void	*img;
	int		img_w;
	int		img_h;
	void	*addr;
	int		bpp;
	int		size_line;
	int		end;
	void	*win;
}				t_txr_win;

typedef struct s_sprite
{
	double	sx;
	double	sy;
}				t_spt;

typedef struct s_map
{
	int			r_w;
	int			r_h;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*s;
	int			floor;
	int			ceiling;
	char		**map;
	int			height;
	int			players_number;

	int			x_iterator;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

	int			map_x;
	int			map_y;
	double		x;
	double		y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		step_x;
	double		step_y;
	int			reach_wall;
	int			side;
	double		perp_wall_dist;

	int			stripeheight;
	int			draw_start;
	int			draw_end;
	double		wallx;
	double		step;
	double		tex_pos;

	t_txr_win	**txr;
	t_txr_win	*wdw;

	int			txre_x;
	int			txre_y;

	double		end;
	double		start;

	double		*zbuffer;

	int			k_w;
	int			k_s;
	double		m_speed;
	int			k_r;
	double		olddir_x;
	double		oldplane_x;
	double		r_speed;
	int			k_l;
	int			k_a;
	int			k_d;
	int			screenshot_flag;

	int			spt_qty;
	int			*spt_sqc;
	double		*spt_dist;
	t_spt		**spt;

	double		spt_x;
	double		spt_y;
	double		inv;
	double		trf_x;
	double		trf_y;
	int			sptscr_x;
	int			spt_height;
	int			draws_y;
	int			drawe_y;
	int			spt_width;
	int			draws_x;
	int			drawe_x;
	int			sptline;
	int			color;

	int			txtflag;
	int			cfflag;

	int			musflag;
}				t_all;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	process_map(t_all *ptr);
int		exit_error(int err);
void	map_validator(t_all *ptr);
void	raycasting (t_all *ptr);
int		process_keys (t_all *ptr);
void	upload_texture_qty (t_all *ptr);
int		key_on (int key, t_all *ptr);
int		key_off (int key, t_all *ptr);
int		go_out(void);
int		main(int argc, char **argv);
void	read_mapfile(t_all *ptr, t_list **head);
t_all	*init_ptr(void);
void	where_wall_was_hit(t_all *ptr);
void	upload_ceiling_wall_floor(t_all *ptr);
void	player_sight_angle( char c, t_all *ptr);
void	print_bmp_file(t_all *ptr);
void	process_sprites(t_all *ptr);
void	my_mlx_pixel_put( t_txr_win *wdw, int x, int y, int color);
void	sprite_put_together(t_all *ptr);
int		exit_subfunction1(int err);
int		exit_subfunction2(int err);
int		exit_subfunction3(int err);
int		exit_subfunction4(int err);
int		exit_subfunction5(int err);
void	*arrays_free(char **s);
int		arr_length(char **str);
void	process_char(char **s);
void	process_char2(char **s2);
void	process_commas(char **s2);
void	process_resolution(char *str, t_all *ptr);
void	process_color(t_all *ptr, char *str);
char	*process_texture(char	*str, t_all *ptr);
void	parse_texture_ns(char *str);
void	parse_texture_we(char *str);
void	init_rays1 (t_all *ptr);
void	init_rays2 (t_all *ptr);
void	spt_pos_rel_to_cam (t_all *ptr, int num);
void	trans_inv_cam_mtx (t_all *ptr);
void	calc_spt_height(t_all *ptr);
void	calc_spt_bottom_top_pix (t_all *ptr);
void	calc_spt_width (t_all *ptr);
void	calc_spt_left_right_pix (t_all *ptr);

#endif