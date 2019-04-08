/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:12:42 by mchi              #+#    #+#             */
/*   Updated: 2019/04/07 16:12:44 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float		vec4_dot(t_vec4 lhs, t_vec4 rhs)
{
	float	result;

	result = 0;
	result += lhs.x * rhs.x;
	result += lhs.y * rhs.y;
	result += lhs.z * rhs.z;
	return (result);
}

t_vec4		vec4_cross(t_vec4 lhs, t_vec4 rhs)
{
	t_vec4	result;

	result.x = lhs.y * rhs.z - lhs.z * rhs.y;
	result.y = -lhs.x * rhs.z + lhs.z * rhs.x;
	result.z = lhs.x * rhs.y - lhs.y * rhs.x;
	result.w = 0;
	return (result);
}

float		vec4_abs(t_vec4 vec)
{
	float	result;

	result = vec.x * vec.x;
	result += vec.y * vec.y;
	result += vec.z * vec.z;
	return (sqrt(result));
}

t_vec4		vec4_norm(t_vec4 vec)
{
	t_vec4	result;
	float	length;

	length = vec4_abs(vec);
	result.x = vec.x / length;
	result.y = vec.y / length;
	result.z = vec.z / length;
	return (result);
}

t_vec4		vec4_mul(t_vec4 lhs, float rhs)
{
	lhs.x *= rhs;
	lhs.y *= rhs;
	lhs.z *= rhs;
	return (lhs);
}
