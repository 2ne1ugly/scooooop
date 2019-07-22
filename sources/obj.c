/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:00:55 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:23:28 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_world_from_obj(t_obj *obj, t_mat mat)
{
	t_mat rot;
	t_mat trans;

	get_rot_from_ypr(obj->ypr, rot);
	get_trans_from_pos(obj->pos, trans);
	mul_mat(rot, trans, mat);
}

void	align_pos(t_obj *obj)
{
	size_t	i;
	t_vec3	center;
	t_vec3	*pos;

	set_vec3(center, 0, 0, 0);
	i = 0;
	while (i < obj->pos_vec->size)
	{
		pos = index_cxxvec(obj->pos_vec, i);
		add_vec(center, *pos, 3, center);
		i++;
	}
	mul_vec(center, 3, -1.0f / obj->pos_vec->size);
	i = 0;
	while (i < obj->pos_vec->size)
	{
		pos = index_cxxvec(obj->pos_vec, i);
		add_vec(center, *pos, 3, *pos);
		i++;
	}
}

/*
** maybe change this to struct dispatch
*/

void	parse_obj_line(t_obj *obj, char *line, char *dir)
{
	char	*type;

	if (!line || !*line || *line == '#')
		return ;
	type = strsep(&line, " ");
	if (strcmp(type, "v") == 0)
		parse_v(obj, line);
	else if (strcmp(type, "f") == 0)
		parse_f(obj, line);
	else if (strcmp(type, "o") == 0)
		parse_o(obj, line);
	else if (strcmp(type, "mtllib") == 0)
		parse_mtllib(obj, line, dir);
	else if (strcmp(type, "usemtl") == 0)
		parse_usemtl(obj, line);
	else if (strcmp(type, "s") == 0)
		parse_s(obj, line);
	else
		fatal("unknown token");
}

void	load_obj(t_obj *obj, const char *path)
{
	char	*data;
	char	*pos;
	char	*line;
	char	*dir;

	set_default_mtl(obj);
	data = read_file(path, NULL);
	pos = strrchr(path, '/');
	dir = malloc((size_t)(pos - path + 1));
	memcpy(dir, path, pos - path);
	dir[pos - path] = '\0';
	pos = data;
	while (pos)
	{
		line = strsep(&pos, "\n");
		parse_obj_line(obj, line, dir);
	}
	free(dir);
	align_pos(obj);
	if (obj->smooth == 0)
		fill_flat_vtx_vec(obj);
	else
		fill_smooth_vtx_vec(obj);
	free(data);
}
