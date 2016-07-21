/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:28:28 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

void		solve_for_sphere(t_vec3 *obsv, t_vec3 *vector, double *root)
{
	double	a;
	double	b;
	double	c;
	double	discrim;

	a = vecdot(vector, vector);
	b = 2 * vecdot(vector, obsv);
	c = vecdot(obsv, obsv) - pow(100, 2);
	discrim = pow(b, 2) - 4 * a * c;
	if (discrim >= 0)
	{
		root[0] = (-b - sqrt(discrim)) / (2 * a);
		root[1] = (-b + sqrt(discrim)) / (2 * a);
	}
	else
	{
		root[0] = -1;
		root[1] = -1;
	}
}

void		solve_for_cylinder(t_vec3 *obsv, t_vec3 *vector, double *root)
{
	double	a;
	double	b;
	double	c;
	double	discrim;

	a = pow(vector->x, 2) + pow(vector->y, 2);
	b = 2 * (obsv->x * vector->x + obsv->y * vector->y);
	c = pow(obsv->x, 2) + pow(obsv->y, 2) - pow(100 / 1.5, 2);
	discrim = pow(b, 2) - 4 * a * c;
	if (discrim >= 0)
	{
		root[0] = (-b - sqrt(discrim)) / (2 * a);
		root[1] = (-b + sqrt(discrim)) / (2 * a);
	}
	else
	{
		root[0] = -1;
		root[1] = -1;
	}
}

void		solve_for_cone(t_vec3 *obsv, t_vec3 *vector, double *root)
{
	double		new_z;
	double		a;
	double		b;
	double		c;
	double		discrim;

	new_z = 0.7 * vector->z;
	a = pow(vector->x, 2) + pow(vector->y, 2) - pow(new_z, 2);
	b = 2 * (obsv->x * vector->x + obsv->y * vector->y
			- obsv->z * new_z);
	c = pow(obsv->x, 2) + pow(obsv->y, 2)
		- pow(obsv->z, 2);
	discrim = pow(b, 2) - 4 * a * c;
	if (discrim >= 0)
	{
		root[0] = (-b - sqrt(discrim)) / (2 * a);
		root[1] = (-b + sqrt(discrim)) / (2 * a);
	}
	else
	{
		root[0] = -1;
		root[1] = -1;
	}
}

void		solve_for_plane(t_vec3 *obsv, t_vec3 *vector, double *root)
{
	if (vector->z < 0.000001 && vector->z > -0.000001)
		root[0] = -1;
	else
		root[0] = -obsv->z / vector->z;
	root[1] = -1;
}
