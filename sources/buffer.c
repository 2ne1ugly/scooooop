/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:43:07 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 12:26:41 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_buffers(t_obj *obj)
{
	glBindVertexArray(obj->vtx_arr);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vtx_buff);
	glBufferData(GL_ARRAY_BUFFER,
		(long)(obj->vtx_vec->size * sizeof(t_vtx)),
		obj->vtx_vec->data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vtx_buff);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(t_vtx), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		sizeof(t_vtx), (void *)sizeof(t_vec3));
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

void	init_buffers(t_obj *obj)
{
	glGenBuffers(1, &obj->vtx_buff);
	glGenVertexArrays(1, &obj->vtx_arr);
	obj->vtx_vec = create_cxxvec(sizeof(t_vtx));
	obj->pos_vec = create_cxxvec(sizeof(t_vec3));
	obj->mtl_vec = create_cxxvec(sizeof(t_mtl));
	obj->poly_vec = create_cxxvec(sizeof(t_cxxvec));
}
