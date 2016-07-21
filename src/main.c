/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 10:58:46 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 13:25:57 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/rtv1.h"

int		main(void)
{
	t_scene		scene;

	if (!(scene.mlx_ptr = mlx_init()))
		return (erro_msg("mlx_init()"));
	init_all(&scene);
	loading(&scene);
	display(&scene);
	return (0);
}
