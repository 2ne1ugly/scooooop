/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:14:56 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 13:38:47 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	setup_obj_space(t_obj_file *obj_file, char **lines)
{
	int i;

	i = 0;
	obj_file->vertex_count = 0;
	obj_file->face_count = 0;
	while (lines[i] != NULL)
	{
		if (lines[i][0] == 'v')
			obj_file->vertex_count++;
		else if (lines[i][0] == 'f')
			obj_file->face_count++;
		i++;
	}
	obj_file->vertices = malloc(sizeof(obj_file->vertex_count));
	obj_file->faces = malloc(sizeof(obj_file->face_count));
}

void	parse_vertex_line(t_vec4 *vec, char **tokens)
{
	int length;

	length = array_len(tokens);
	if (length < 3 || length > 4)
		fatal_error("incorrect vertex data number in object file");
	vec->x = atof(tokens[1]);
	vec->y = atof(tokens[2]);
	vec->z = atof(tokens[3]);
	if (length == 4)
		vec->w = atof(tokens[4]);
	else
		vec->w = 1.0f;
}

void	parse_face_line(GLuint **face, char **tokens)
{
	int length;

	(void)length;
	(void)face;
	(void)tokens;
/*
	length = array_len(tokens);
	if (length < 3 || length > 4)
		fatal_error("incorrect vertex data number in object file");
	vec->x = atof(tokens[1]);
	vec->y = atof(tokens[2]);
	vec->z = atof(tokens[3]);
	if (length == 4)
		vec->w = atof(tokens[4]);
	else
		vec->w = 1.0f;
		*/
}

void	insert_data(t_obj_file *obj_file, char **lines)
{
	int i;
	int vc;
	int fc;
	char **tokens;

	i = 0;
	vc = 0;
	fc = 0;
	while (lines[i] != NULL)
	{
		tokens = ft_strsplit(lines[i], ' ');
		if (lines[i][0] == 'v')
			parse_vertex_line(&obj_file->vertices[vc++], &tokens[1]);
		else if (lines[i][0] == 'f')
			parse_face_line(&obj_file->faces[fc++], &tokens[1]);
		free_tab(tokens);
		i++;
	}
}

void	parse_obj(t_obj_file *obj_file)
{
	char **lines;

	lines = ft_strsplit(obj_file->data, '\n');
	setup_obj_space(obj_file, lines);
	free_tab(lines);
}
