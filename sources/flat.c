/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:46:35 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:24:06 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	triple_push(t_cxxvec *vec, void *a, void *b, void *c)
{
	push_back_cxxvec(vec, a);
	push_back_cxxvec(vec, b);
	push_back_cxxvec(vec, c);
}

void	push_flat_vtx_from_poly(t_obj *obj, t_cxxvec *poly)
{
	size_t		i;
	t_vtx		vec[3];

	cpy_vec(vec[0].pos, index_cxxvec(obj->pos_vec,
		*(unsigned *)index_cxxvec(poly, 0) - 1), 3);
	cpy_vec(vec[1].pos, index_cxxvec(obj->pos_vec,
		*(unsigned *)index_cxxvec(poly, 1) - 1), 3);
	cpy_vec(vec[2].pos, index_cxxvec(obj->pos_vec,
		*(unsigned *)index_cxxvec(poly, 2) - 1), 3);
	get_norm_from_tri(vec[0].pos, vec[1].pos, vec[2].pos, vec[0].nor);
	cpy_vec(vec[1].nor, vec[0].nor, 3);
	cpy_vec(vec[2].nor, vec[0].nor, 3);
	triple_push(obj->vtx_vec, &vec[2], &vec[1], &vec[0]);
	i = 2;
	while (++i < poly->size)
	{
		vec[1] = vec[2];
		cpy_vec(vec[2].pos, index_cxxvec(obj->pos_vec,
			*(unsigned *)index_cxxvec(poly, i) - 1), 3);
		triple_push(obj->vtx_vec, &vec[2], &vec[1], &vec[0]);
	}
}

void	fill_flat_vtx_vec(t_obj *obj)
{
	size_t	i;

	i = 0;
	while (i < obj->poly_vec->size)
	{
		push_flat_vtx_from_poly(obj, index_cxxvec(obj->poly_vec, i));
		i++;
	}
}
