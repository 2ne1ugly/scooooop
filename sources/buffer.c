/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 18:43:07 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 10:47:29 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_buffers(t_obj *obj)
{
	glGenBuffers(1, &obj->vtx_buff);
	glGenVertexArrays(1, &obj->vtx_arr);
	obj->vtx_vec = create_cxxvec(sizeof(t_vtx));
	obj->idx_vec = create_cxxvec(sizeof(unsigned long));
	obj->mtl_vec = create_cxxvec(sizeof(t_mtl));
}

