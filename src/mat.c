/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:02:19 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 15:55:15 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat	mat_identity(void)
{
	t_mat ret;

	ret.v[0] = 1.0f;
	ret.v[1] = 0.0f;
	ret.v[2] = 0.0f;
	ret.v[3] = 0.0f;
	ret.v[4] = 0.0f;
	ret.v[5] = 1.0f;
	ret.v[6] = 0.0f;
	ret.v[7] = 0.0f;
	ret.v[8] = 0.0f;
	ret.v[9] = 0.0f;
	ret.v[10] = 1.0f;
	ret.v[11] = 0.0f;
	ret.v[12] = 0.0f;
	ret.v[13] = 0.0f;
	ret.v[14] = 0.0f;
	ret.v[15] = 1.0f;
	return (ret);
}

t_mat	mat_mul(t_mat *lhs, t_mat *rhs)
{
	t_mat	result;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result.v[i * 4+ j] = 0;
			while (k < 4)
			{
				result.v[i * 4 + j] += lhs->v[i * 4 + k] * rhs->v[k * 4 + j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}
