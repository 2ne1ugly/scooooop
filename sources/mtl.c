/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:12:38 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 13:31:10 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_mtl_line(t_obj *obj, char *line, t_mtl *mtl)
{
	char	*type;

	if (!line || !*line || *line == '#')
		return ;
	type = strsep(&line, " ");
	if (strcmp(type, "newmtl") == 0)
		parse_newmtl(obj, line, mtl);
	else if (strcmp(type, "Ns") == 0)
		parse_ns(mtl, line);
	else if (strcmp(type, "Ka") == 0)
		parse_ka(mtl, line);
	else if (strcmp(type, "Kd") == 0)
		parse_kd(mtl, line);
	else if (strcmp(type, "Ks") == 0)
		parse_ks(mtl, line);
	else if (strcmp(type, "d") == 0)
		parse_d(mtl, line);
	else if (strcmp(type, "Ni") == 0)
		parse_ni(mtl, line);
	else if (strcmp(type, "illum") == 0)
		parse_illum(mtl, line);
	else
		fatal("unknown token");
}

void	init_default_mtl(t_mtl *mtl)
{
	*mtl->name = '\0';
	zero_vec(mtl->amb, 3);
	mtl->dif[0] = 0.5f;
	mtl->dif[1] = 0.5f;
	mtl->dif[2] = 0.5f;
	mtl->spec[0] = 1.f;
	mtl->spec[1] = 1.f;
	mtl->spec[2] = 1.f;
	mtl->exp = 42;
	mtl->ir = 1.52f;
	mtl->opac = 0.1f;
	mtl->model = 2;
}

void	load_mtl(t_obj *obj, char *path)
{
	char	*data;
	char	*pos;
	char	*line;
	t_mtl	context;

	init_default_mtl(&context);
	data = read_file(path, NULL);
	pos = data;
	while (pos)
	{
		line = strsep(&pos, "\n");
		parse_mtl_line(obj, line, &context);
	}
	if (*context.name)
		push_back_cxxvec(obj->mtl_vec, &context);
	free(data);
}

void	set_default_mtl(t_obj *obj)
{
	t_mtl	context;

	init_default_mtl(&context);
	context.name[0] = '\0';
	push_back_cxxvec(obj->mtl_vec, &context);
	obj->curr_mtl = index_cxxvec(obj->mtl_vec, obj->mtl_vec->size - 1);
	obj->smooth = -1;
}
