/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:02:06 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 13:39:11 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
/*
int		count_elem(char **pos, char c)
{
	int count;

	count = 0;
	while (**pos == '#' || **pos == c)
	{
		if (**pos != '#')
			count++;
		while (**pos != '\n' && **pos != '\0')
			(*pos)++;
		if (**pos == '\n')
			(*pos)++;
	}
	while (**pos == '\n')
		(*pos)++;
	return (count);
}

int		write_vertex(char **pos, t_vec4 *vec_buff)
{
	int i;

	i = 0;
	while (**pos == '#' || **pos == 'v')
	{
		if (**pos != '#')
		{
			strtok(*pos, " \n");
			vec_buff[i].x = atof(strtok(NULL, " \n"));
			vec_buff[i].y = atof(strtok(NULL, " \n"));
			vec_buff[i].z = atof(strtok(NULL, " \n"));
			vec_buff[i].w = 1;
			i++;
		}
		while (**pos != '\n' && **pos != '\0')
			(*pos)++;
		if (**pos == '\n')
			(*pos)++;
	}
	while (**pos == '\n')
		(*pos)++;
	return (1);
}

int		write_index(char **pos, GLuint *ind_buff)
{
	int i;

	i = 0;
	while (**pos == '#' || **pos == 'f')
	{
		if (**pos != '#')
		{
			strtok(*pos, " \n");
			ind_buff[i] = atoi(strtok(NULL, " \n"));
			ind_buff[i + 1] = atoi(strtok(NULL, " \n"));
			ind_buff[i + 2] = atoi(strtok(NULL, " \n"));
			i += 3;
		}
		while (**pos != '\n' && **pos != '\0')
			(*pos)++;
		if (**pos == '\n')
			(*pos)++;
	}
	while (**pos == '\n')
		(*pos)++;
	return (1);
}
*/

void	init_buffers(t_app *app, t_obj *obj)
{
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
}

void	init_object(t_app *app, char *object)
{
	t_obj		*obj;
	t_obj_file	obj_file;

	obj = &app->obj;
	obj_file.data = read_file(object);
	obj_file.path = object;
	parse_obj(&obj_file);
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
