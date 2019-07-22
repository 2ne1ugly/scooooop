/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:25:50 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:23:32 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_num_9(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[2] += 0.1;
	else
		app->obj.pos[2] += 0.1;
}

void	key_num_1(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[2] -= 0.1;
	else
		app->obj.pos[2] -= 0.1;
}

void	key_r(t_app *app)
{
	app->rotation_mode = !app->rotation_mode;
}

void	key_1(t_app *app)
{
	app->tex_mode = !app->tex_mode;
}
