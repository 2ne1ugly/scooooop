/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:00:55 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 10:53:36 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
	else
		fatal("unknown token");
}

void	load_obj(t_obj *obj, const char *path)
{
	char	*data;
	char	*pos;
	char	*line;
	char	*dir;

	data = read_file(path, NULL);
	pos = strrchr(path, '/');
	dir = malloc(pos - path + 1);
	memcpy(dir, path, pos - path);
	dir[pos - path] = '\0';
	pos = data;
	while (pos)
	{
		line = strsep(&pos, "\n");
		parse_obj_line(app, line, dir);
	}
	free(dir);
}
