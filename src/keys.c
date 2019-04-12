/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:56:10 by mchi              #+#    #+#             */
/*   Updated: 2019/04/11 16:01:01 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	key_press(int keycode, void *param)
{
	t_app	*app;
	t_vec4	dir_foward;
	t_vec4	dir_right;
	t_vec4	dir_up;
//	t_mat	ypr;

	app = param;
	dir_right = (t_vec4){cos(app->cam.ypr.x), 0, -sin(app->cam.ypr.x), 0};
	dir_up = (t_vec4){sin(app->cam.ypr.x) * sin(app->cam.ypr.y),
		cos(app->cam.ypr.y), cos(app->cam.ypr.x) * sin(app->cam.ypr.y), 0};
	dir_foward = (t_vec4){sin(app->cam.ypr.x) * cos(app->cam.ypr.y),
		- sin(app->cam.ypr.y), cos(app->cam.ypr.y) * cos(app->cam.ypr.x), 0};

	if (keycode == 126)
		app->cam.ypr.y -= 0.05;
	if (keycode == 125)
		app->cam.ypr.y += 0.05;
	if (keycode == 123)
		app->cam.ypr.x -= 0.05;
	if (keycode == 124)
		app->cam.ypr.x += 0.05;
	if (keycode == 13)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_foward, 0.2));
	if (keycode == 0)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_right, -0.2));
	if (keycode == 1)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_foward, -0.2));
	if (keycode == 2)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_right, 0.2));
	app->update = 1;
	return (0);
}
