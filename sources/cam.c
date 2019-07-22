/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:17:24 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 11:04:03 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_xyz_from_ypr(t_vec3 ypr, t_vec3 x, t_vec3 y, t_vec3 z)
{
	t_mat rot;

	get_rot_from_ypr(ypr, rot);
	set_vec3(x, 1, 0, 0);
	set_vec3(y, 0, 1, 0);
	set_vec3(z, 0, 0, 1);
	trans_vec3(rot, x);
	trans_vec3(rot, y);
	trans_vec3(rot, z);
}

void	get_view_from_cam(t_cam *cam, t_mat mat)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	memset(mat, 0, sizeof(GLfloat) * 16);
	get_xyz_from_ypr(cam->ypr, x, y, z);
	mul_vec(z, 3, -1);
	mat[0][0] = x[0];
	mat[0][1] = y[0];
	mat[0][2] = z[0];
	mat[1][0] = x[1];
	mat[1][1] = y[1];
	mat[1][2] = z[1];
	mat[2][0] = x[2];
	mat[2][1] = y[2];
	mat[2][2] = z[2];
	mat[3][0] = -dot_vec(x, cam->pos, 3);
	mat[3][1] = -dot_vec(y, cam->pos, 3);
	mat[3][2] = -dot_vec(z, cam->pos, 3);
	mat[3][3] = 1;
}

void	get_proj_from_cam(t_cam *cam, t_mat mat)
{
	memset(mat, 0, sizeof(GLfloat) * 16);
	mat[0][0] = cam->c / cam->aspect;
	mat[1][1] = cam->c;
	mat[2][2] = -(FAR + NEAR) / (FAR - NEAR);
	mat[2][3] = -1;
	mat[3][2] = -2 * FAR * NEAR / (FAR - NEAR);
}

void	init_cam(t_cam *cam)
{
	zero_vec(cam->pos, 3);
	cam->pos[2] = -5;
	zero_vec(cam->ypr, 3);
	cam->fov = PI / 2;
	cam->aspect = WIDTH / (float)HEIGHT;
	cam->c = 1.0f / (float)tan(cam->fov / 2);
}
