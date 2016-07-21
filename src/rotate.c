/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/15 10:49:36 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

static void	rot_x(t_vec3 *vec, t_vec3 *rot_fac, int invert)
{
	t_vec3	rot_vec;

	rot_vec.y = vec->y * cos(invert * rot_fac->x)
		+ vec->z * -sin(invert * rot_fac->x);
	rot_vec.z = vec->y * sin(invert * rot_fac->x)
		+ vec->z * cos(invert * rot_fac->x);
	vec->y = rot_vec.y;
	vec->z = rot_vec.z;
}

static void	rot_y(t_vec3 *vec, t_vec3 *rot_fac, int invert)
{
	t_vec3	rot_vec;

	rot_vec.x = vec->x * cos(invert * rot_fac->y)
		+ vec->z * sin(invert * rot_fac->y);
	rot_vec.z = vec->x * -sin(invert * rot_fac->y)
		+ vec->z * cos(invert * rot_fac->y);
	vec->x = rot_vec.x;
	vec->z = rot_vec.z;
}

static void	rot_z(t_vec3 *vec, t_vec3 *rot_fac, int invert)
{
	t_vec3	rot_vec;

	rot_vec.x = vec->x * cos(invert * rot_fac->z)
		+ vec->y * -sin(invert * rot_fac->z);
	rot_vec.y = vec->x * sin(invert * rot_fac->z)
		+ vec->y * cos(invert * rot_fac->z);
	vec->x = rot_vec.x;
	vec->y = rot_vec.y;
}

void		all_rot(t_vec3 *vec, t_vec3 *rot_fac, int invert)
{
	if (invert == -1)
	{
		rot_x(vec, rot_fac, invert);
		rot_y(vec, rot_fac, invert);
		rot_z(vec, rot_fac, invert);
	}
	else
	{
		rot_z(vec, rot_fac, invert);
		rot_y(vec, rot_fac, invert);
		rot_x(vec, rot_fac, invert);
	}
}
