/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:18:40 by mchi              #+#    #+#             */
/*   Updated: 2019/07/20 13:44:13 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_left(t_app *app)
{
	app->cam.ypr[0] += -0.1;
}

void	key_right(t_app *app)
{
	app->cam.ypr[0] += 0.1;
}

void	key_up(t_app *app)
{
	app->cam.ypr[1] += -0.1;
}

void	key_down(t_app *app)
{
	app->cam.ypr[1] += 0.1;
}
