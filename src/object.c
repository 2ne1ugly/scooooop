/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:02:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/11 16:34:43 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_buffers(t_app *app, t_obj *obj)
{
	app->ind_buff = 0;
	glGenBuffers(1, &app->ind_buff);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, app->ind_buff);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->index_count * sizeof(GLuint), obj->indices, GL_STATIC_DRAW);
	app->vbo = 0;
	glGenBuffers(1, &app->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, app->vbo);
	glBufferData(GL_ARRAY_BUFFER, obj->vertex_count * sizeof(t_vec4), obj->vertices, GL_STATIC_DRAW);
	app->vao = 0;
	glGenVertexArrays(1, &app->vao);
	glBindVertexArray(app->vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, app->vbo);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
}

void	setup_data(t_obj *obj, t_obj_file *obj_file)
{
	int i;
	int j;
	int k;
	int total_indices;

	obj->vertices = obj_file->vertices;
	obj->vertex_count = obj_file->vertex_count;
	i = -1;
	total_indices = 0;
	while (++i < obj_file->poly_count)
		total_indices += (obj_file->polies[i].vertex_count - 2) * 3;
	obj->indices = malloc(sizeof(GLuint) * total_indices);
	obj->index_count = total_indices;
	i = -1;
	k = 0;
	while (++i < obj_file->poly_count)
	{
		j = -1;
		while (++j < obj_file->polies[i].vertex_count)
		{
			if (obj_file->polies[i].vertex[j] > 0)
				obj->indices[k++] = obj_file->polies[i].vertex[j] - 1;
			else if (obj_file->polies[i].vertex[j] < 0)
				obj->indices[k++] = obj_file->polies[i].vertex_count - obj_file->polies[i].vertex[j];
		}
		free(obj_file->polies[i].vertex);
	}
	free(obj_file->data);
	free(obj_file->mtl_files);
	free(obj_file->normals);
	free(obj_file->par_vertices);
	free(obj_file->polies);
	free(obj_file->tex_coords);
	free(obj_file->lines);
}

void	init_object(t_app *app, char *object)
{
	t_obj		*obj;
	t_obj_file	obj_file;

	obj = &app->obj;
	obj_file.data = read_file(object);
	obj_file.path = object;
	parse_obj(&obj_file);
	setup_data(obj, &obj_file);
//	obj->vertex_count = count_elem(&next_data, 'v');
//	obj->vertices = malloc(sizeof(t_vec4) * obj->vertex_count);
//	write_vertex(&prev_data, obj->vertices);
//	obj->index_count = 3 * count_elem(&next_data, 'f');
//	obj->indices = malloc(sizeof(GLuint) * obj->index_count);
//	write_index(&prev_data, obj->indices);
	init_buffers(app, obj);
	obj->ypr = (t_vec4){0.0f, 0.0f, 0.0f, 1.0f};
	obj->pos = (t_vec4){0.0f, 0.0f, 0.0f, 1.0f};
}
