/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:59:26 by simzam            #+#    #+#             */
/*   Updated: 2016/07/05 12:04:16 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rtv1.h"

void		img_data_pixel_put(t_scene *scene, int x, int y, t_int colour)
{
	int		i;
	int		dest;
	t_int	new_colour;

	new_colour = mlx_get_color_value(scene->mlx_ptr, colour);
	dest = y * scene->view.sl + x * scene->view.bpp;
	i = -1;
	while (++i < scene->view.bpp)
	{
		if (scene->view.endian == 0)
			scene->view.img[dest + i] = new_colour >> (i << 3) & 255;
		else
			scene->view.img[dest + i] = new_colour
				>> (scene->view.bpp - ((i + 1) << 3)) & 255;
	}
}
