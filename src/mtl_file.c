/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtl_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:20:09 by mchi              #+#    #+#             */
/*   Updated: 2019/04/11 16:29:17 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_mtl(t_mtl *mtl, char *name)
{
	mtl->name = name;
	mtl->ambient = (t_vec4){1.0f, 1.0f, 1.0f, 1.0f};
	mtl->diffuse = (t_vec4){1.0f, 1.0f, 1.0f, 1.0f};
	mtl->specular = (t_vec4){0.0f, 0.0f, 0.0f, 0.0f};
	mtl->spec_exp = 1;
	mtl->opacity = 1;
	mtl->illum_model = 0;
}

void	fill_mtl(t_mtl *mtls, char **lines)
{
	int		i;
	int		mtl_idx;
	char	**tokens;

	i = -1;
	mtl_idx = -1;
	while (lines[++i] != NULL)
	{
		tokens = ft_strsplit(lines[i], ' ');
		if (strcmp(tokens[0], "newmtl") == 0)
			init_mtl(&mtls[++mtl_idx], tokens[1]);
		else if (strcmp(tokens[0], "Ka") == 0)
			parse_3val_line(&mtls[mtl_idx].ambient, &tokens[1]);
		else if (strcmp(tokens[0], "Kd") == 0)
			parse_3val_line(&mtls[mtl_idx].diffuse, &tokens[1]);
		else if (strcmp(tokens[0], "Ks") == 0)
			parse_3val_line(&mtls[mtl_idx].specular, &tokens[1]);
		else if (strcmp(tokens[0], "Ns") == 0)
			parse_1val_float_line(&mtls[mtl_idx].spec_exp, &tokens[1]);
		else if (strcmp(tokens[0], "d") == 0)
			parse_1val_float_line(&mtls[mtl_idx].spec_exp, &tokens[1]);
		else if (strcmp(tokens[0], "Tr") == 0)
			parse_tr_line(&mtls[mtl_idx].spec_exp, &tokens[1]);
		else if (strcmp(tokens[0], "illum") == 0)
			parse_1val_int_line(&mtls[mtl_idx].illum_model, &tokens[1]);
		free_tab(tokens);
	}
}

void	add_mtl(t_mtl_file *mtl, char *line)
{
	int		i;
	char	**lines;
	char	**tokens;

	i = 0;
	while (!isspace(line[i]))
		i++;
	while (isspace(line[i]))
		i++;
	mtl->path = ft_strjoin("resources/", &line[i]);
	mtl->data = read_file(mtl->path);
	lines = ft_strsplit(mtl->data, '\n');
	mtl->mtl_count = 0;
	i = 0;
	while (lines[i] != NULL)
	{
		tokens = ft_strsplit(lines[i], ' ');
		if (strcmp(tokens[0], "newmtl") == 0)
			mtl->mtl_count++;
		free_tab(tokens);
		i++;
	}
	mtl->mtls = malloc(sizeof(t_mtl) * mtl->mtl_count);
	fill_mtl(mtl->mtls, lines);
	free_tab(lines);
}

void	apply_mtl(t_obj_file *obj, char **tokens)
{
	(void)obj;
	(void)tokens;
}
