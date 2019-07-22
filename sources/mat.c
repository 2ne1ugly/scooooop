/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:08:55 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 10:59:13 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_rot_from_ypr(t_vec3 ypr, t_mat mat)
{
	memset(mat, 0, sizeof(float) * 16);
	mat[0][0] = cos(ypr[0]) * cos(ypr[2]) +
		sin(ypr[0]) * sin(ypr[1]) * sin(ypr[2]);
	mat[0][1] = sin(ypr[2]) * cos(ypr[1]);
	mat[0][2] = -sin(ypr[0]) * cos(ypr[2]) +
		cos(ypr[0]) * sin(ypr[1]) * sin(ypr[2]);
	mat[1][0] = -cos(ypr[0]) * sin(ypr[2]) +
		sin(ypr[0]) * sin(ypr[1]) * cos(ypr[2]);
	mat[1][1] = cos(ypr[2]) * cos(ypr[1]);
	mat[1][2] = sin(ypr[2]) * sin(ypr[0]) +
		cos(ypr[0]) * sin(ypr[1]) * cos(ypr[2]);
	mat[2][0] = sin(ypr[0]) * cos(ypr[1]);
	mat[2][1] = -sin(ypr[1]);
	mat[2][2] = cos(ypr[0]) * cos(ypr[1]);
	mat[3][3] = 1;
}

void	get_trans_from_pos(t_vec3 pos, t_mat mat)
{
	memset(mat, 0, sizeof(float) * 16);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
	mat[3][0] = pos[0];
	mat[3][1] = pos[1];
	mat[3][2] = pos[2];
}

void	mul_mat(t_mat lhs, t_mat rhs, t_mat mat)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			mat[i][j] = 0;
			while (k < 4)
			{
				mat[i][j] += lhs[i][k] * rhs[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}
