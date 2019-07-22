/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:51:23 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 11:00:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_ks(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f %f %f",
		&mtl->spec[0], &mtl->spec[1], &mtl->spec[2]) < 3)
		fatal("invalid obj");
}

void	parse_d(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	mtl->opac = atof(assert_parse(&args, " "));
}

void	parse_ni(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	mtl->ir = atof(assert_parse(&args, " "));
}

void	parse_illum(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	mtl->model = atoi(assert_parse(&args, " "));
}
