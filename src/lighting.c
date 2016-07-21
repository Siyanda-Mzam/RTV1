/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:59:26 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:27:24 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		vec_normal(t_vec3 *normal, t_vec3 *p, t_obj *obj)
{
	if (obj->type == BALL)
		*normal = (t_vec3){p->x, p->y, p->z};
	else if (obj->type == PIPE)
		*normal = (t_vec3){p->x, p->y, 20};
	else if (obj->type == HAT)
		*normal = (t_vec3){p->x, p->y, -0.1 * p->z};
	else if (obj->type == SHEET)
		*normal = (t_vec3){0, 0, 100};
}

t_int		compute_light(t_scene *scene, t_vec3 *spl)
{
	t_vec3	p;
	t_vec3	light;
	t_vec3	normal;
	double	cos_a;
	t_int	new_colour;

	scene->vector = vecopx(&scene->vector, scene->t);
	p = vecadd(&scene->obsv, &scene->vector);
	light = vecsub(spl, &p);
	new_colour = scene->cur_obj->colour;
	vec_normal(&normal, &p, scene->cur_obj);
	cos_a = vecdot(&normal, &light) / (veclength(&normal) * veclength(&light));
	if (cos_a >= 0 && cos_a <= 1)
		new_colour = mult_colour(scene->cur_obj->colour, cos_a);
	else
		new_colour = 0;
	return (new_colour);
}
