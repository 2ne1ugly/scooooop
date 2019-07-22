/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:19:13 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 10:55:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	normal_vec(GLfloat *lhs, int size)
{
	int		i;
	GLfloat	length;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += lhs[i] * lhs[i];
		i++;
	}
	length = (float)sqrt(length);
	i = 0;
	while (i < size)
	{
		lhs[i] /= length;
		i++;
	}
}

void	cross_vec(GLfloat *lhs, GLfloat *rhs, t_vec3 out)
{
	out[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
	out[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
	out[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];
}

void	zero_vec(GLfloat *v, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		v[i] = 0;
		i++;
	}
}

void	mul_vec(GLfloat *v, int size, GLfloat k)
{
	int i;

	i = 0;
	while (i < size)
	{
		v[i] *= k;
		i++;
	}
}

GLfloat	dot_vec(GLfloat *lhs, GLfloat *rhs, int size)
{
	int		i;
	float	sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += lhs[i] * rhs[i];
		i++;
	}
	return (sum);
}
