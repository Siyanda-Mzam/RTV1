/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:21:15 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 14:25:23 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 1080
# define HEIGHT 800
# include "vector.h"
# include <mlx.h>

typedef unsigned int						t_int;

typedef enum								e_object_type_id
{
	BALL,
	HAT,
	PIPE,
	SHEET
}											t_type;

typedef struct								s_scene_objects_properties
{
	t_type									type;
	t_vec3									pos;
	t_vec3									rot;
	t_int									colour;
	struct s_scene_objects_properties		*next;
}											t_obj;

typedef struct								s_scene_image_properties
{
	void									*mlx_ptr;
	char									*img;
	int										x;
	int										y;
	int										bpp;
	int										sl;
	int										endian;
}											t_img;

typedef struct								s_scene_properties
{
	void									*mlx_ptr;
	void									*mlx_win;
	t_img									view;
	t_obj									*object_record;
	t_obj									*cur_obj;
	t_vec3									spl_1;
	t_vec3									spl_2;
	t_vec3									obsv;
	t_vec3									obvrot;
	t_vec3									plane;
	t_vec3									vector;
	double									fov;
	double									t;
}											t_scene;

void										init_all(t_scene *scene);
void										loading(t_scene *scene);
void										display(t_scene *scene);
void										all_rot(t_vec3 *xyz, t_vec3 *rot,
																	int invert);
void										solve_for_sphere(t_vec3 *eye,
												t_vec3 *vector, double *k);
void										solve_for_cylinder(t_vec3 *eye,
												t_vec3 *vector, double *k);
void										solve_for_cone(t_vec3 *eye,
												t_vec3 *vector, double *k);
void										solve_for_plane(t_vec3 *eye,
												t_vec3 *vector, double *k);
void										scan_and_compute(t_vec3 *obsv,
												t_vec3 *vector,
												t_obj *obj, double *t);
t_int										compute_light(t_scene *scene,
												t_vec3 *spot);
t_int										compute_shades(t_scene *scene,
												t_vec3 *spot, t_int cur_color);
t_obj										*spawn_object(t_type type,
											t_vec3 pos,
											t_vec3 rot, t_int colour);
void										img_data_pixel_put(t_scene
											*scene, int x, int y,
											t_int colour);
void										ft_putstr(const char *str);
int											get_key(int keycode,
											t_scene *scene);
int											handle_event(t_scene *scene);
void										pb_object(t_obj **list, t_obj *new);
t_int										mult_colour(t_int colour,
											double perc);
t_int										mix_two_colours(t_int color1,
												t_int color2);
int											erro_msg(char *str);

#endif
