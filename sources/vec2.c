/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:28:05 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 13:12:03 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	add_vec(GLfloat *lhs, GLfloat *rhs, int size, GLfloat *out)
{
	int i;

	i = 0;
	while (i < size)
	{
		out[i] = lhs[i] + rhs[i];
		i++;
	}
}

void	trans_vec3(t_mat mat, t_vec3 vec)
{
	t_vec3	tmp;

	tmp[0] = vec[0] * mat[0][0] + vec[1] * mat[1][0] +
		vec[2] * mat[2][0] + mat[3][0];
	tmp[1] = vec[0] * mat[0][1] + vec[1] * mat[1][1] +
		vec[2] * mat[2][1] + mat[3][1];
	tmp[2] = vec[0] * mat[0][2] + vec[1] * mat[1][2] +
		vec[2] * mat[2][2] + mat[3][2];
	vec[0] = tmp[0];
	vec[1] = tmp[1];
	vec[2] = tmp[2];
}

void	set_vec3(t_vec3 vec, float x, float y, float z)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
}

void	cpy_vec(GLfloat *dst, GLfloat *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	get_norm_from_tri(t_vec3 a, t_vec3 b, t_vec3 c, t_vec3 n)
{
	t_vec3	ba;
	t_vec3	ca;

	cpy_vec(ba, a, 3);
	mul_vec(ba, 3, -1);
	cpy_vec(ca, ba, 3);
	add_vec(ba, b, 3, ba);
	add_vec(ca, c, 3, ba);
	cross_vec(ba, ca, n);
	normal_vec(n, 3);
	n[0] = fabsf(n[0]);
	n[1] = fabsf(n[1]);
	n[2] = fabsf(n[2]);
}
