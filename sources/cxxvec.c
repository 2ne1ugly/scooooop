/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cxxvec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:18:41 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 11:03:22 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_cxxvec	*create_cxxvec(size_t elem_size)
{
	t_cxxvec	*out;

	out = malloc(sizeof(t_cxxvec));
	if (!out)
		fatal("malloc fail");
	out->cap = 8;
	out->size = 0;
	out->elem_size = elem_size;
	out->data = malloc(elem_size * out->cap);
	if (!out->data)
		fatal("malloc fail");
	return (out);
}

void		reserve_cxxvec(t_cxxvec *vec)
{
	void	*data;

	data = malloc(vec->elem_size * vec->cap * 2);
	if (!data)
		fatal("malloc fail");
	memcpy(data, vec->data, vec->elem_size * vec->size);
	vec->cap *= 2;
	free(vec->data);
	vec->data = data;
}

void		push_back_cxxvec(t_cxxvec *vec, void *elem)
{
	if (vec->size == vec->cap)
		reserve_cxxvec(vec);
	memcpy(vec->data + vec->size * vec->elem_size, elem, vec->elem_size);
	vec->size++;
}

void		*index_cxxvec(t_cxxvec *vec, size_t i)
{
	if (i >= vec->size)
		fatal("idx out of range");
	return (vec->data + i * vec->elem_size);
}
