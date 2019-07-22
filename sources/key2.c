/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:22:05 by mchi              #+#    #+#             */
/*   Updated: 2019/07/20 13:44:43 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_w(t_app *app)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	get_xyz_from_ypr(app->cam.ypr, x, y, z);
	mul_vec(z, 3, 0.1f);
	add_vec(app->cam.pos, z, 3, app->cam.pos);
}

void	key_a(t_app *app)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	get_xyz_from_ypr(app->cam.ypr, x, y, z);
	mul_vec(x, 3, -0.1f);
	add_vec(app->cam.pos, x, 3, app->cam.pos);
}

void	key_s(t_app *app)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	get_xyz_from_ypr(app->cam.ypr, x, y, z);
	mul_vec(z, 3, -0.1f);
	add_vec(app->cam.pos, z, 3, app->cam.pos);
}

void	key_d(t_app *app)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	get_xyz_from_ypr(app->cam.ypr, x, y, z);
	mul_vec(x, 3, 0.1f);
	add_vec(app->cam.pos, x, 3, app->cam.pos);
}
