/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:23 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:31:13 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/rtv1.h"

void		move_ray(t_vec3 *obsv, t_vec3 *vector, t_obj *tmp, int invert)
{
	if (invert == 1)
	{
		all_rot(obsv, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
	obsv->x += invert * tmp->pos.x;
	obsv->y += invert * tmp->pos.y;
	obsv->z += invert * tmp->pos.z;
	vector->x += invert * tmp->pos.x;
	vector->y += invert * tmp->pos.y;
	vector->z += invert * tmp->pos.z;
	if (invert == -1)
	{
		all_rot(obsv, &tmp->rot, invert);
		all_rot(vector, &tmp->rot, invert);
	}
}

void		scan_and_compute(t_vec3 *obsv, t_vec3 *vector, t_obj *obj,
		double *t)
{
	move_ray(obsv, vector, obj, -1);
	if (obj->type == BALL)
		solve_for_sphere(obsv, vector, t);
	else if (obj->type == PIPE)
		solve_for_cylinder(obsv, vector, t);
	else if (obj->type == HAT)
		solve_for_cone(obsv, vector, t);
	else if (obj->type == SHEET)
		solve_for_plane(obsv, vector, t);
	move_ray(obsv, vector, obj, 1);
}

static void	find_intersections(int x, int y, t_scene *scene)
{
	double	t[2];
	t_obj	*tmp;
	t_int	colour;

	scene->t = 20000;
	scene->cur_obj = NULL;
	tmp = scene->object_record;
	while (tmp)
	{
		scan_and_compute(&scene->obsv, &scene->vector, tmp, t);
		if (t[0] >= 0 && scene->t > t[0] && (scene->cur_obj = tmp))
			scene->t = t[0];
		if (t[1] >= 0 && scene->t > t[1] && (scene->cur_obj = tmp))
			scene->t = t[1];
		tmp = tmp->next;
	}
	if (scene->cur_obj != NULL)
	{
		colour = mix_two_colours(compute_light(scene, &scene->spl_2),
		compute_light(scene, &scene->spl_2));
		colour = mult_colour(colour, 1.7);
		colour = compute_shades(scene, &scene->spl_1, colour);
		colour = compute_shades(scene, &scene->spl_2, colour);
		img_data_pixel_put(scene, x, y, colour);
	}
}

static void	ray_trace(int x, int y, t_scene *scene)
{
	scene->plane.x = scene->fov;
	scene->plane.y = (WIDTH / 2) - x;
	scene->plane.z = (HEIGHT / 2) - y;
	scene->vector = vecsub(&scene->plane, &scene->obsv);
	all_rot(&scene->vector, &scene->obvrot, 1);
	find_intersections(x, y, scene);
}

void		loading(t_scene *scene)
{
	int		x;
	int		y;
	int		loading_percentage;

	loading_percentage = -1;
	ft_putstr("Loading ");
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			ray_trace(x, y, scene);
			if (100 * (y + x * HEIGHT) / (WIDTH * HEIGHT) >
					loading_percentage + 1)
			{
				loading_percentage = 100 * (y + x * HEIGHT) / (WIDTH * HEIGHT);
				ft_putstr("\033[42m \033[0m");
			}
		}
	}
	ft_putstr("\n");
}
