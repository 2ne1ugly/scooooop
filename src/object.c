/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:02:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/08 16:38:58 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_object(t_app *app)
{
	t_obj *obj;

	obj = &app->obj;
	obj->vertex_count = 8;
	obj->vertices = malloc(sizeof(t_vec4) * obj->vertex_count);
	obj->vertices[0] = (t_vec4){-0.5f, -0.5f, 0.5f, 1.0f};
	obj->vertices[1] = (t_vec4){0.5f, -0.5f, 0.5f, 1.0f};
	obj->vertices[2] = (t_vec4){-0.5f, 0.5f, 0.5f, 1.0f};
	obj->vertices[3] = (t_vec4){0.5f, 0.5f, 0.5f, 1.0f};
	obj->vertices[4] = (t_vec4){-0.5f, 0.5f, -0.5f, 1.0f};
	obj->vertices[5] = (t_vec4){0.5f, 0.5f, -0.5f, 1.0f};
	obj->vertices[6] = (t_vec4){-0.5f, -0.5f, -0.5f, 1.0f};
	obj->vertices[7] = (t_vec4){0.5f, -0.5f, -0.5f, 1.0f};

	obj->index_count = 36;
	obj->indices = malloc(sizeof(GLuint) * obj->index_count);
	obj->indices[0] = 0;
	obj->indices[1] = 1;
	obj->indices[2] = 2;
	obj->indices[3] = 2;
	obj->indices[4] = 1;
	obj->indices[5] = 3;
	obj->indices[6] = 2;
	obj->indices[7] = 3;
	obj->indices[8] = 4;
	obj->indices[9] = 4;
	obj->indices[10] = 3;
	obj->indices[11] = 5;
	obj->indices[12] = 6;
	obj->indices[13] = 7;
	obj->indices[14] = 0;
	obj->indices[15] = 0;
	obj->indices[16] = 7;
	obj->indices[17] = 3;
	obj->indices[18] = 6;
	obj->indices[19] = 7;
	obj->indices[20] = 0;
	obj->indices[21] = 0;
	obj->indices[22] = 7;
	obj->indices[23] = 3;
	obj->indices[24] = 1;
	obj->indices[25] = 7;
	obj->indices[26] = 3;
	obj->indices[27] = 3;
	obj->indices[28] = 7;
	obj->indices[29] = 5;
	obj->indices[30] = 6;
	obj->indices[31] = 0;
	obj->indices[32] = 4;
	obj->indices[33] = 4;
	obj->indices[34] = 0;
	obj->indices[35] = 2;
	app->ind_buff = 0;
	glGenBuffers(1, &app->ind_buff);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, app->ind_buff);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->index_count * sizeof(GLuint), obj->indices, GL_STATIC_DRAW);
	app->vbo = 0;
	glGenBuffers(1, &app->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, app->vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->index_count * sizeof(t_vec4), obj->vertices, GL_STATIC_DRAW);
	app->vao = 0;
	glGenVertexArrays(1, &app->vao);
	glBindVertexArray(app->vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, app->vbo);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
	obj->ypr = (t_vec4){0.0f, 0.0f, 0.0f, 1.0f};
	obj->pos = (t_vec4){0.0f, 0.0f, 0.0f, 1.0f};
}
