/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:12 by xchalle           #+#    #+#             */
/*   Updated: 2021/05/25 10:15:55 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# define FOV 60
# define ESC 65307
# define Z 122
# define Q 113
# define D 100
# define S 115
# define CUB 64
# define RIGHT_ARROW 65363
# define CROUCH 65507
# define LEFT_ARROW 65361

typedef struct s_r
{
	double	xstep;
	double	ystep;
	double	y;
	double	x;
	double	side_x;
	double	side_y;
}				t_r;

typedef struct s_s
{
	char	**array;
	int		reso[2];
	int		floor[3];
	int		ceiling[3];
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*s;
	int		i;
	int		max;
	int		posi;
	int		posj;
	char	chara;
	int		floor_verif;
	int		ceiling_verif;
	int		reso_verif;
	int		s_verif;
	int		we_verif;
	int		ea_veri;
	int		no_verif;
	int		so_verif;
	int		chara_verif;
	int		stocki;
}				t_s;

typedef struct s_d
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_img;
	int		y_img;
}				t_d;

typedef struct s_c
{
	double	lx1;
	double	ly1;
	double	lx2;
	double	ly2;
	double	ptx;
	double	pty;
	double	centerx;
	double	centery;
	double	den;
	double	u;
	double	t;
	double	base_x;
	double	base_y;
}				t_c;

typedef struct s_p
{
	double	posx;
	double	newposx;
	double	posy;
	double	newposy;
	double	walkdirx;
	double	walkdir;
	double	rotadir;
	double	rotangle;
	double	movespeed;
	double	rotaspeed;
	double	fov;
	double	hitx_vert;
	double	hity_vert;
	double	hity_vert_s;
	double	hitx_horz_s;
	double	hity_horz;
	double	hitx_horz;
	int		bool_vert;
	int		bool_vert_pre;
	int		crouch;
	double	dist_s[40][2];
	double	dist_os;
	double	pourcent_s;
}				t_p;

typedef struct s_g
{
	char	*stockstr;
	char	*freestr;
}				t_g;

typedef struct s_u
{
	double	d;
	double	p;
}				t_u;

typedef struct s_h
{
	t_d		img;
	t_d		img2;
	t_d		img3;
	t_d		img4;
	t_d		img5;
	t_d		img6;
	t_p		p;
	t_s		s;
	t_r		r;
	t_c		c;
	t_u		*u;
	int		sprite;
	int		fovi;
	double	cub_size;
	double	spangle;
	double	spangle2;
	double	pourcent;
	double	dist_max;
	int		a;
	int		i;
	int		sprt;
	int		save;
	int		tmp;
	int		tmp2;
	int		map_verif;
	int		u_verif;
	int		img_verif;
	int		longe;
	int		count;
}				t_h;

void			summon_so(char *str, t_s *s, int i);
void			summon_no(char *str, t_s *s, int i);
void			summon_we(char *str, t_s *s, int i);
void			summon_ea(char *str, t_s *s, int i);
void			summon_s(char *str, t_s *s, int i);
void			summon_f(char *str, t_h *h, int i);
void			summon_c(char *str, t_h *h, int i);
void			summon_r(char *str, t_h *h, int i);
void			summon_map(char *str, int fd, t_h *h);
int				summon_bin(char *str, t_h *h);
void			switch_setting(char *str, t_h *h);
void			read_setting(t_h *h, char *file);
void			check_setting(t_s *s);
void			init_setting(t_s *s);
void			parsing_map(t_h *h, int fd, char *str, int i);
void			ft_create_win(t_s s);
void			ft_draw_map(t_h *h);
void			ft_player(t_h *h);
void			my_mlx_pixel_put(t_h *h, int x, int y, int color);
void			draw_rect(t_h *h, int x, int y, int color);
void			arg_check(int argc, char **argv, t_h *h);
int				ft_hitwall(t_h *h, double posx, double posy);
int				ft_hitwall2(t_h *h, double posx, double posy);
int				wall_no(t_h *h);
int				wall_so(t_h *h);
int				wall(t_h *h);
int				wall_we(t_h *h);
int				wall_s(t_h *h);
void			write_map(char *str, int o, int i, t_h *h);
void			alloc_array(t_h *h, int i);
void			check_map(t_h *h);
void			check_map2_1(t_h *h);
void			check_map3(t_h *h);
int				check_verif(t_h *h);
void			check_map2(t_h *h);
void			write_bmp(t_h *h);
int				ft_charset_tot(char c);
int				ft_charset(char c);
int				charset_str(char *str);
void			ft_free_struct(t_h *h);
double			ft_raycasting_hor(t_h *h, double posx, double posy);
double			ft_raycasting_ver(t_h *h, double posx, double posy);
int				my_mlx_pixel_find(t_d *d, int x, int y);
double			ft_raycasting_ver2(t_h *h, double posx, double posy);
double			ft_raycasting_hor2(t_h *h, double posx, double posy);
void			pourcent_img_vert(t_h *h);
void			pourcent_img_horz(t_h *h);
void			sort_sprite(t_h *h);
void			draw_line2(t_h *h, int i, double dist_max);
void			reset_sprite(t_h *h);
void			draw_line(t_h *h, int i, int color);
int				press(int keycode, t_h *h);
void			ft_init_h(t_h *h, int screensizex, int screensizey);
int				rien(t_h *h);
void			ft_move(t_h *h, long *ceiling, long *floor);
int				release(int keycode, t_h *h);
int				end(t_h *h);
int				check_verif_soft(t_h *h);
void			ft_destroy_img(t_h *h);
void			ft_destroy_img_end(t_h *h);
void			check_color_range(t_h *h);
void			trim(long double *di, double *j);
void			check_line(char *str, t_h *h, int i);
int				chars(char c);
void			error_struct_2(t_h *h, int i, char *str, int e);
void			error_struct_2bis(t_h *h, char *str, int e);
void			check_int_reso(t_h *h);
int				count_str(char *str, int i, int j);

#endif
