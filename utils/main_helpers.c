/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:23:57 by simzam            #+#    #+#             */
/*   Updated: 2016/07/21 12:18:48 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		display(t_scene *scene)
{
	scene->mlx_win = mlx_new_window(scene->mlx_ptr, WIDTH, HEIGHT,
									"RT-HoneyBadger");
	mlx_expose_hook(scene->mlx_win, &handle_event, scene);
	mlx_key_hook(scene->mlx_win, &get_key, scene);
	mlx_loop(scene->mlx_ptr);
}

void		init_all(t_scene *scene)
{
	scene->view.mlx_ptr = mlx_new_image(scene->mlx_ptr, WIDTH, HEIGHT);
	scene->view.img = mlx_get_data_addr(scene->view.mlx_ptr, &scene->view.bpp,
										&scene->view.sl, &scene->view.endian);
	scene->view.bpp = scene->view.bpp / 8;
	scene->fov = WIDTH / (tan(0.2));
	scene->obsv = (t_vec3){-scene->fov - 4000, 0, 600};
	scene->obvrot = (t_vec3){0, 0, 0};
	scene->spl_1 = (t_vec3){0, 1000, 600};
	scene->spl_2 = (t_vec3){0, -1000, 600};
	scene->object_record = 0;
	pb_object(&scene->object_record, spawn_object(PIPE, (t_vec3){-10, 0, 0},
									(t_vec3){0, 0, 45}, 11734783));
	pb_object(&scene->object_record, spawn_object(BALL, (t_vec3){200, -130, 20},
									(t_vec3){30, 0, 0}, 5631765));
	pb_object(&scene->object_record, spawn_object(HAT, (t_vec3){100, 0, 80},
									(t_vec3){0, 0, 30}, 16736117));
	pb_object(&scene->object_record, spawn_object(SHEET, (t_vec3){0, 0, -90},
									(t_vec3){0, 0, 0}, 255));
}
