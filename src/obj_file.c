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

void	count_obj_data(t_obj_file *obj_file, char **lines)
{
	int i;

	obj_file->vertex_count = 0;
	obj_file->tex_coord_count = 0;
	obj_file->normal_count = 0;
	obj_file->par_vertex_count =0;
	obj_file->poly_count = 0;
	obj_file->line_count = 0;
	i = -1;
	while (lines[++i] != NULL)
		if (lines[i][0] == 'v')
			obj_file->vertex_count++;
		else if (lines[i][0] == 'v' && lines[i][1] == 't')
			obj_file->tex_coord_count++;
		else if (lines[i][0] == 'v' && lines[i][1] == 'n')
			obj_file->normal_count++;
		else if (lines[i][0] == 'v' && lines[i][1] == 'p')
			obj_file->par_vertex_count++;
		else if (lines[i][0] == 'f')
			obj_file->poly_count++;
		else if (lines[i][0] == 'l')
			obj_file->line_count++;
}

void	malloc_obj_data(t_obj_file *obj_file)
{
	obj_file->vertices = malloc(sizeof(obj_file->vertex_count));
	obj_file->tex_coords = malloc(sizeof(obj_file->tex_coord_count));
	obj_file->normals = malloc(sizeof(obj_file->normal_count));
	obj_file->par_vertices = malloc(sizeof(obj_file->par_vertex_count));
	obj_file->polies = malloc(sizeof(obj_file->poly_count));
	obj_file->lines = malloc(sizeof(obj_file->line_count));
}

void	insert_data(t_obj_file *obj_file, char **lines)
{
	int i[7];
	char **tokens;

	memset(i, 0, sizeof(int) * 7);
	while (lines[i[0]] != NULL)
	{
		tokens = ft_strsplit(lines[i[0]], ' ');
		if (lines[i[0]][0] == 'v')
			parse_vertex_line(&obj_file->vertices[i[1]++], tokens);
		else if (lines[i[0]][0] == 'v' && lines[i[0]][1] == 't')
			parse_param_line(&obj_file->tex_coords[i[2]++], tokens);
		else if (lines[i[0]][0] == 'v' && lines[i[0]][1] == 'n')
			parse_normal_line(&obj_file->normals[i[3]++], tokens);
		else if (lines[i[0]][0] == 'v' && lines[i[0]][1] == 'p')
			parse_param_line(&obj_file->par_vertices[i[4]++], tokens);
		else if (lines[i[0]][0] == 'f')
			parse_face_line(&obj_file->polies[i[5]++], tokens);
		else if (lines[i[0]][0] == 'l')
			parse_line_line(&obj_file->lines[i[6]++], tokens);
		free_tab(tokens);
		i[0]++;
	}
}

void	parse_obj(t_obj_file *obj_file)
{
	char **lines;

	lines = ft_strsplit(obj_file->data, '\n');
	setup_obj_data(obj_file, lines);
	malloc_obj_data(obj_file);
	free_tab(lines);
}
