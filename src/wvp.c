/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wvp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:36:46 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 16:19:51 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	mat_look_at(t_vec4 eye, float pitch, float yaw)
{
	t_vec4	x_axis;
	t_vec4	y_axis;
	t_vec4	z_axis;
	t_mat	result;

	x_axis = (t_vec4){cos(yaw), 0, -sin(yaw), 0};
	y_axis = (t_vec4){sin(yaw) * sin(pitch),
		cos(pitch), cos(yaw) * sin(pitch), 0};
	z_axis = (t_vec4){sin(yaw) * cos(pitch),
		-sin(pitch), cos(pitch) * cos(yaw), 0};
	result = mat_identity();
	result.v[0] = x_axis.x;
	result.v[1] = y_axis.x;
	result.v[2] = z_axis.x;
	result.v[4] = x_axis.y;
	result.v[5] = y_axis.y;
	result.v[6] = z_axis.y;
	result.v[8] = x_axis.z;
	result.v[9] = y_axis.z;
	result.v[10] = z_axis.z;
	result.v[12] = -vec4_dot(x_axis, eye);
	result.v[13] = -vec4_dot(y_axis, eye);
	result.v[14] = -vec4_dot(z_axis, eye);
	result.v[15] = 0;
	return (result);
}

t_mat	mat_ypr(t_vec4 *ypr)
{
	t_mat	mat;

	mat.v[0] = cos(ypr->y) * cos(ypr->z);
	mat.v[1] = cos(ypr->y) * sin(ypr->z);
	mat.v[2] = -sin(ypr->y);
	mat.v[3] = 0;
	mat.v[4] = sin(ypr->x) * sin(ypr->y) * cos(ypr->z) -
		cos(ypr->x) * sin(ypr->z);
	mat.v[5] = sin(ypr->x) * sin(ypr->y) * sin(ypr->z) +
		cos(ypr->x) * cos(ypr->z);
	mat.v[6] = sin(ypr->x) * cos(ypr->y);
	mat.v[7] = 0;
	mat.v[8] = cos(ypr->x) * sin(ypr->y) * cos(ypr->z) +
		sin(ypr->x) * sin(ypr->z);
	mat.v[9] = cos(ypr->x) * sin(ypr->y) * sin(ypr->z) -
		sin(ypr->x) * cos(ypr->z);
	mat.v[10] = cos(ypr->x) * cos(ypr->y);
	mat.v[11] = 0;
	mat.v[12] = 0;
	mat.v[13] = 0;
	mat.v[14] = 0;
	mat.v[15] = 1;
	return (mat);
}

t_mat	mat_transl(t_vec4 *trl)
{
	t_mat	mat;

	mat = mat_identity();
	mat.v[12] = trl->x;
	mat.v[13] = trl->y;
	mat.v[14] = trl->z;
	return (mat);
}

t_mat	mat_world(t_obj *obj)
{
	t_mat ypr;
	t_mat trl;

	ypr = mat_ypr(&obj->ypr);
	trl = mat_transl(&obj->pos);
	return (mat_mul(&trl, &ypr));
}


t_mat	mat_proj(t_cam *cam)
{
	t_mat	mat;
	float	z_range;

	z_range = cam->far - cam->near;
	mat = mat_identity();
	mat.v[0] = 1.0f / (cam->c * cam->aspect);
	mat.v[5] = 1.0f / cam->c;
	mat.v[10] = -(cam->far + cam->near) / (z_range);
	mat.v[11] = -1.0f;
	mat.v[14] = -(2 * cam->far * cam->near) / (z_range);
	mat.v[15] = 0;
	return (mat);
}
