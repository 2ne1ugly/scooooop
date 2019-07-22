/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:22:31 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 11:03:17 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_num_4(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[0] -= 0.1;
	else
		app->obj.pos[0] -= 0.1;
}

void	key_num_6(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[0] += 0.1;
	else
		app->obj.pos[0] += 0.1;
}

void	key_num_8(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[1] += 0.1;
	else
		app->obj.pos[1] += 0.1;
}

void	key_num_2(t_app *app)
{
	if (app->rotation_mode)
		app->obj.ypr[1] -= 0.1;
	else
		app->obj.pos[1] -= 0.1;
}
