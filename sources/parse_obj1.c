/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:37:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 10:58:51 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_v(t_obj *obj, char *args)
{
	t_vec3	pos;

	if (!args)
		fatal("invalid obj");
	pos[0] = atof(assert_parse(&args, " "));
	pos[1] = atof(assert_parse(&args, " "));
	pos[2] = atof(assert_parse(&args, " "));
	push_back_cxxvec(obj->pos_vec, pos);
}

void	parse_f(t_obj *obj, char *args)
{
	unsigned	idx;
	t_cxxvec	*poly;
	char		*token;

	if (!args)
		fatal("invalid obj");
	poly = create_cxxvec(sizeof(unsigned));
	if (!poly)
		fatal("malloc fail");
	idx = atoi(assert_parse(&args, " "));
	push_back_cxxvec(poly, &idx);
	idx = atoi(assert_parse(&args, " "));
	push_back_cxxvec(poly, &idx);
	idx = atoi(assert_parse(&args, " "));
	push_back_cxxvec(poly, &idx);
	while ((token = strsep(&args, " ")))
	{
		idx = atoi(token);
		push_back_cxxvec(poly, &idx);
	}
	push_back_cxxvec(obj->poly_vec, poly);
	free(poly);
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
	name = assert_parse(&args, " ");
	path = malloc(strlen(dir) + strlen(name) + 5);
	*path = '\0';
	strcat(path, dir);
	strcat(path, "/");
	strcat(path, name);
	load_mtl(obj, path);
	free(path);
}

/*
**	only one mtl for object
*/

void	parse_usemtl(t_obj *obj, char *args)
{
	char	*name;
	t_mtl	*mtl;
	size_t	i;

	if (!args)
		fatal("invalid obj");
	name = assert_parse(&args, " ");
	i = 0;
	while (i < obj->mtl_vec->size)
	{
		mtl = index_cxxvec(obj->mtl_vec, i);
		if (strcmp(name, mtl->name) == 0)
		{
			obj->curr_mtl = mtl;
			return ;
		}
		i++;
	}
	fatal("couldn't find material");
}
