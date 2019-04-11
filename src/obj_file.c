/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:14:56 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 13:38:47 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		increase_count(t_obj_file *obj, char *head)
{
	if (head[0] != '#' && strcmp(head, "") != 0 &&
		strcmp(head, "usemtl") != 0 && strcmp(head, "o") != 0 &&
		strcmp(head, "g") != 0 && strcmp(head, "s") != 0)
		if (strcmp(head, "v") == 0)
			obj->vertex_count++;
		else if (strcmp(head, "vt") == 0)
			obj->tex_coord_count++;
		else if (strcmp(head, "vn") == 0)
			obj->normal_count++;
		else if (strcmp(head, "vp") == 0)
			obj->par_vertex_count++;
		else if (strcmp(head, "f") == 0)
			obj->poly_count++;
		else if (strcmp(head, "l") == 0)
			obj->line_count++;
		else if (strcmp(head, "mtllib") == 0)
			obj->mtl_file_count++;
		else
			fatal_error("invalid/non-parsable obj");
}

void	count_obj_data(t_obj_file *obj, char **lines)
{
	int i;
	char **tokens;

	i = -1;
	obj->vertex_count = 0;
	obj->tex_coord_count = 0;
	obj->normal_count = 0;
	obj->par_vertex_count =0;
	obj->poly_count = 0;
	obj->line_count = 0;
	obj->mtl_file_count = 0;
	while (lines[++i] != NULL)
	{
		tokens = ft_strsplit(lines[i], ' ');
		increase_count(obj, tokens[0]);
		free_tab(tokens);
	}
	obj->vertices = malloc(sizeof(obj->vertex_count));
	obj->tex_coords = malloc(sizeof(obj->tex_coord_count));
	obj->normals = malloc(sizeof(obj->normal_count));
	obj->par_vertices = malloc(sizeof(obj->par_vertex_count));
	obj->polies = malloc(sizeof(obj->poly_count));
	obj->lines = malloc(sizeof(obj->line_count));
	obj->mtl_files = malloc(sizeof(obj->mtl_file_count));
}

void	insert_data(t_obj_file *obj, char **lines)
{
	int i[8];
	char **tokens;

	memset(i, 0, sizeof(int) * 8);
	while (lines[i[0]] != NULL)
	{
		tokens = ft_strsplit(lines[i[0]], ' ');
		if (strcmp(tokens[0], "v") == 0)
			parse_vertex_line(&obj->vertices[i[1]++], &tokens[1]);
		else if (strcmp(tokens[0], "vt") == 0)
			parse_param_line(&obj->tex_coords[i[2]++], &tokens[1]);
		else if (strcmp(tokens[0], "vn") == 0)
			parse_normal_line(&obj->normals[i[3]++], &tokens[1]);
		else if (strcmp(tokens[0], "vp") == 0)
			parse_param_line(&obj->par_vertices[i[4]++], &tokens[1]);
		else if (strcmp(tokens[0], "f") == 0)
			parse_face_line(&obj->polies[i[5]++], &tokens[1], obj->curr_mtl);
		else if (strcmp(tokens[0], "l") == 0)
			parse_line_line(&obj->lines[i[6]++], &tokens[1], obj->curr_mtl);
		else if (strcmp(tokens[0], "mtllib") == 0)
			add_mtl(obj->mtl_files[i[7]++], &tokens[1]);
		else if (strcmp(tokens[0], "usemtl") == 0)
			apply_mtl(obj, &tokens[1]);
		free_tab(tokens);
		i[0]++;
	}
}

void	parse_obj(t_obj_file *obj)
{
	char **lines;

	lines = ft_strsplit(obj->data, '\n');
	count_obj_data(obj, lines);
	obj->curr_mtl = NULL;
	memset(obj->mtl_files, 0, sizeof(t_mtl *) * 8);
	insert_data(obj, lines);
	free_tab(lines);
}
