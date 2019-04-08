/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:56:10 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 16:13:17 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	key_press(int keycode, void *param)
{
	t_app	*app;
	t_vec4	dir_foward;
	t_vec4	dir_right;
	t_vec4	dir_up;
	t_mat	ypr;

	app = param;
	dir_foward = (t_vec4){0.0f, 0.0f, 1.0f, 0.0f};
	dir_right = (t_vec4){1.0f, 0.0f, 0.0f, 0.0f};
	dir_up = (t_vec4){0.0f, 1.0f, 0.0f, 0.0f};
	ypr = mat_ypr(&app->cam.ypr);
	dir_foward = vec4_trans(&ypr, dir_foward);
	dir_right = vec4_trans(&ypr, dir_right);
	dir_up = vec4_trans(&ypr, dir_up);

	if (keycode == 126)
		app->cam.ypr.y += 0.05;
	if (keycode == 125)
		app->cam.ypr.y -= 0.05;
	if (keycode == 123)
		app->cam.ypr.x -= 0.05;
	if (keycode == 124)
		app->cam.ypr.x += 0.05;
	if (keycode == 13)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_foward, 0.2));
	if (keycode == 0)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_right, 0.2));
	if (keycode == 1)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_foward, -0.2));
	if (keycode == 2)
		app->cam.pos = vec4_add(app->cam.pos, vec4_mul(dir_right, -0.2));
	app->update = 1;
	return (0);
}
