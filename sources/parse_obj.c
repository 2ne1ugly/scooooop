/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:37:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 11:31:13 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_v(t_obj *obj, char *args)
{
	t_vtx	elem;

	if (!args)
		fatal("invalid obj");
	zero_vec(elem->norm, 3);
	if (sscanf(args, "%f %f %f", &elem.pos[0], &elem.pos[1], &elem.pos[2]) < 3)
		fatal("invalid obj");
	push_back_cxxvec(obj->vtx_vec, &elem);
}

void	parse_f(t_obj *obj, char *args)
{
	unsigned long	indices[3];

	if (!args)
		fatal("invalid obj");
	if (sscanf(args, "%lu %lu %lu", &indices[0], &indices[1], &indices[2]) < 3)
		fatal("invalid obj");
	push_back_cxxvec(obj->idx_vec, &indices[0]);
	push_back_cxxvec(obj->idx_vec, &indices[1]);
	push_back_cxxvec(obj->idx_vec, &indices[2]);
}

/*
**	only one object is expected for now.
*/

void	parse_o(t_obj *obj, char *args)
{
	(void)obj;
	(void)args;
}

void	parse_mtllib(t_obj *obj, char *args, char *dir)
{
	char	*name;
	char	*path;

	if (!args)
		fatal("invalid obj");
	name = NULL;
	if (sscanf(args, "%s", name) < 1)
		fatal("invalid obj");
	path = malloc(strlen(dir) + strlen(name) + 1);
	*path = '\0';
	strcat(path, dir);
	strcat(path, "/");
	strcat(path, name);
	load_mtl(app, path);
	free(path);
}

/*
**	only one mtl for object
*/

void	parse_usemtl(t_app *app, char *args)
{
	char	*name;
	t_mtl	*mtl;
	size_t		i;

	if (!args)
		fatal("invalid obj");
	name = NULL;
	if (sscanf(args, "%s", name) < 1)
		fatal("invalid obj");
	i = 0;
	while (i < app->mtl_vec->size)
	{
		mtl = index_cxxvec(app->mtl_vec, i);
		if (strcmp(name, mtl->name) == 0)
		{
			app->curr_mtl = mtl;
			return ;
		}
		i++;
	}
	fatal("couldn't find material");
}
