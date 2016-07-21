/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:21:15 by simzam            #+#    #+#             */
/*   Updated: 2016/07/15 10:38:34 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/rtv1.h"

t_obj			*spawn_object(t_type type, t_vec3 pos, t_vec3 rot, t_int colour)
{
	t_obj		*new;

	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	new->type = type;
	new->pos = pos;
	new->rot = rot;
	new->colour = colour;
	new->next = NULL;
	return (new);
}

void			pb_object(t_obj **object_record, t_obj *new)
{
	t_obj		*tmp;

	if (!*object_record)
		*object_record = new;
	else
	{
		tmp = *object_record;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
