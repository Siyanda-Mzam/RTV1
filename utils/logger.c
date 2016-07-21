/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:01:23 by simzam            #+#    #+#             */
/*   Updated: 2016/07/17 17:01:24 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_strlen(const char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

void			ft_putstr(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int				erro_msg(char *str)
{
	write(2, "rtv1: ", 6);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "fucked out", 9);
	}
	write(2, "\n", 1);
	return (1);
}
