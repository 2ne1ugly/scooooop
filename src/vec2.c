/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:12:37 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 12:29:21 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scop.h"

t_vec4		vec4_sub(t_vec4 lhs, t_vec4 rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	lhs.z -= rhs.z;
	lhs.w = lhs.w || rhs.w;
	return (lhs);
}

t_vec4		vec4_add(t_vec4 lhs, t_vec4 rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;
	lhs.w = lhs.w || rhs.w;
	return (lhs);
}

t_vec4		vec4_trans(t_mat *mat, t_vec4 vec)
{
	t_vec4	result;

	result.x = vec.x * mat->v[0] + vec.y * mat->v[4] +
		vec.z * mat->v[8] + vec.w * mat->v[12];
	result.y = vec.x * mat->v[1] + vec.y * mat->v[5] +
		vec.z * mat->v[9] + vec.w * mat->v[13];
	result.z = vec.x * mat->v[2] + vec.y * mat->v[6] +
		vec.z * mat->v[10] + vec.w * mat->v[14];
	result.w = vec.x * mat->v[3] + vec.y * mat->v[7] +
		vec.z * mat->v[11] + vec.w * mat->v[15];
	return (result);
}
