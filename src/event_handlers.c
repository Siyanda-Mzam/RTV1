/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:23 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:24:50 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "../includes/rtv1.h"

int		get_key(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == 65307 || keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		handle_event(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx_ptr, scene->mlx_win,
			scene->view.mlx_ptr, 0, 0);
	return (0);
}
