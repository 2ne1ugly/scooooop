/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 12:19:18 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:23:52 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	add_normal(t_obj *obj, t_cxxvec *poly, t_vec3 *norm)
{
	size_t		i;
	unsigned	idx[3];
	t_vec3		*pos[3];
	t_vec3		curr_norm;

	idx[0] = *(unsigned *)index_cxxvec(poly, 0) - 1;
	idx[1] = *(unsigned *)index_cxxvec(poly, 1) - 1;
	idx[2] = *(unsigned *)index_cxxvec(poly, 2) - 1;
	pos[0] = index_cxxvec(obj->pos_vec, idx[0]);
	pos[1] = index_cxxvec(obj->pos_vec, idx[1]);
	pos[2] = index_cxxvec(obj->pos_vec, idx[2]);
	get_norm_from_tri(*pos[0], *pos[1], *pos[2], curr_norm);
	add_vec(norm[idx[0]], curr_norm, 3, norm[idx[0]]);
	add_vec(norm[idx[1]], curr_norm, 3, norm[idx[1]]);
	add_vec(norm[idx[2]], curr_norm, 3, norm[idx[2]]);
	i = 2;
	while (++i < poly->size)
	{
		idx[2] = *(unsigned *)index_cxxvec(poly, i) - 1;
		add_vec(norm[idx[2]], curr_norm, 3, norm[idx[2]]);
	}
}

void	push_smooth_vtx_from_poly(t_obj *obj, t_cxxvec *poly, t_vec3 *norm)
{
	size_t		i;
	unsigned	idx[3];
	t_vtx		vec[3];

	idx[0] = *(unsigned *)index_cxxvec(poly, 0) - 1;
	idx[1] = *(unsigned *)index_cxxvec(poly, 1) - 1;
	idx[2] = *(unsigned *)index_cxxvec(poly, 2) - 1;
	cpy_vec(vec[0].pos, index_cxxvec(obj->pos_vec, idx[0]), 3);
	cpy_vec(vec[1].pos, index_cxxvec(obj->pos_vec, idx[1]), 3);
	cpy_vec(vec[2].pos, index_cxxvec(obj->pos_vec, idx[2]), 3);
	cpy_vec(vec[0].nor, norm[idx[0]], 3);
	cpy_vec(vec[1].nor, norm[idx[1]], 3);
	cpy_vec(vec[2].nor, norm[idx[2]], 3);
	triple_push(obj->vtx_vec, &vec[2], &vec[1], &vec[0]);
	i = 2;
	while (++i < poly->size)
	{
		vec[1] = vec[2];
		idx[2] = *(unsigned *)index_cxxvec(poly, i) - 1;
		cpy_vec(vec[2].pos, index_cxxvec(obj->pos_vec, idx[2]), 3);
		cpy_vec(vec[2].nor, norm[idx[2]], 3);
		triple_push(obj->vtx_vec, &vec[2], &vec[1], &vec[0]);
	}
}

void	fill_smooth_vtx_vec(t_obj *obj)
{
	t_vec3	*norm;
	size_t	i;

	norm = malloc(sizeof(t_vec3) * obj->pos_vec->size);
	memset(norm, 0, sizeof(t_vec3) * obj->pos_vec->size);
	i = 0;
	while (i < obj->poly_vec->size)
	{
		add_normal(obj, index_cxxvec(obj->poly_vec, i), norm);
		i++;
	}
	i = 0;
	while (i < obj->poly_vec->size)
	{
		push_smooth_vtx_from_poly(obj, index_cxxvec(obj->poly_vec, i), norm);
		i++;
	}
	free(norm);
}
