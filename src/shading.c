/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:59:26 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:38:59 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	init_stuff(t_scene *scene, t_vec3 *spl, t_vec3 *p, t_vec3 *light)
{
	scene->vector = vecopx(&scene->vector, scene->t);
	*p = vecadd(&scene->obsv, &scene->vector);
	*light = vecsub(spl, p);
}

t_int		compute_shades(t_scene *scene, t_vec3 *spl, t_int cur_color)
{
	t_vec3	p;
	t_vec3	light;
	double	closest_root;
	double	t[2];
	t_obj	*tmp;

	if ((tmp = scene->object_record) && scene->cur_obj->type != SHEET)
		return (cur_color);
	init_stuff(scene, spl, &p, &light);
	closest_root = -1;
	while (tmp)
	{
		if (tmp != scene->cur_obj)
		{
			scan_and_compute(&p, &light, tmp, t);
			if ((t[0] > 0.1 && t[0] < 0.9))
				closest_root = t[0];
			if ((t[1] > 0.1 && t[1] < 0.9))
				closest_root = t[1];
		}
		tmp = tmp->next;
	}
	if ((closest_root != -1))
		cur_color = mult_colour(cur_color, 0.2);
	return (cur_color);
}
