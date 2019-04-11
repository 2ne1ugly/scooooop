/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:16:49 by mchi              #+#    #+#             */
/*   Updated: 2019/04/10 15:16:49 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_vertex_line(t_vec4 *vec, char **tokens)
{
	int length;

	length = array_len(tokens);
	if (length < 3 || length > 4)
		fatal_error("incorrect vertex data number in object file");
	vec->x = atof(tokens[0]);
	vec->y = atof(tokens[1]);
	vec->z = atof(tokens[2]);
	if (length == 4)
		vec->w = atof(tokens[3]);
	else
		vec->w = 1.0f;
}

void	parse_param_line(t_vec4 *tex, char **tokens)
{
	int length;

	length = array_len(tokens);
	if (length < 1 || length > 3)
		fatal_error("param number incorrect");
	tex->x = atof(tokens[0]);
	tex->y = 0.0f;
	tex->z = 0.0f;
	if (length == 1)
		return ;
	tex->y = atof(tokens[1]);
	if (length == 2)
		return ;
	tex->z = atof(tokens[2]);
}

void	parse_normal_line(t_vec4 *norm, char **tokens)
{
	int length;

	length = array_len(tokens);
	if (length != 3)
		fatal_error("normal do not contain 3 values");
	norm->x = atof(tokens[0]);
	norm->y = atof(tokens[1]);
	norm->z = atof(tokens[2]);	
}

void	parse_face_line(t_poly *poly, char **tokens, t_mtl *mtl)
{
	int	i;
	char **tabs;

	poly->vertex_count = array_len(tokens);
	if (poly->vertex_count < 3)
		fatal_error("incorrect vertex data number in object file");
	poly->vertex = malloc(sizeof(GLuint) * (poly->vertex_count));
	poly->tex_coord = malloc(sizeof(GLuint) * (poly->vertex_count));
	poly->normal = malloc(sizeof(GLuint) * (poly->vertex_count));
	i = 0;
	while (i < poly->vertex_count)
	{
		tabs = ft_strsplit(tokens[i], '/');
		poly->vertex[i] = atoi(tabs[0]);
		poly->tex_coord[i] = 0;
		poly->normal[i] = 0;
		if (tabs[1] != NULL)
		{
			poly->tex_coord[i] = atoi(tabs[1]);
			if (tabs[2] != NULL)
				poly->normal[i] = atoi(tabs[2]);
		}
		free_tab(tabs);
		i++;
	}
	poly->material = mtl;
}

void	parse_line_line(t_line *line, char **tokens, t_mtl *mtl)
{
	int	i;

	line->vertex_count = array_len(tokens);
	if (line->vertex_count < 2)
		fatal_error("the line consists only one line");
	line->vertex = malloc(sizeof(GLuint) * (line->vertex_count));
	i = 0;
	while (i < line->vertex_count)
	{
		line->vertex[i] = atoi(tokens[i]);
		i++;
	}
	line->material = mtl;
}
