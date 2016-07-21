/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:25:22 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_int		mult_colour(t_int colour, double ratio)
{
	int		i;
	int		colour_channels[3];

	i = -1;
	while (++i < 3)
	{
		colour_channels[i] = (colour >> ((2 - i) << 3)) & 255;
		colour_channels[i] *= ratio;
		if (colour_channels[i] > 255)
			colour_channels[i] = 255;
		if (colour_channels[i] < 0)
			colour_channels[i] = 0;
	}
	return ((colour_channels[0] << 8) + (colour_channels[1] << 16) +
			colour_channels[2]);
}

t_int		mix_two_colours(t_int color1, t_int color2)
{
	int		i;
	int		colour_channels1[3];
	int		colour_channels2[3];

	i = -1;
	while (++i < 3)
	{
		colour_channels1[i] = (color1 >> ((2 - i) << 3)) & 255;
		colour_channels2[i] = (color2 >> ((2 - i) << 3)) & 255;
		colour_channels1[i] = colour_channels1[i] + colour_channels2[i];
		if (colour_channels1[i] > 255)
			colour_channels1[i] = 255;
		if (colour_channels1[i] < 0)
			colour_channels1[i] = 0;
	}
	return ((colour_channels1[0] << 16) + (colour_channels1[1] << 8) +
			colour_channels1[2]);
}
