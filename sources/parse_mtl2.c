/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mtl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:51:23 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 11:15:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	parse_Ks(t_mtl *mtl, char *args)
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
	if (sscanf(args, "%f", &mtl->opac) < 1)
		fatal("invalid obj");
}

void	parse_Ni(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%f", &mtl->ir) < 1)
		fatal("invalid obj");
}

void	parse_illum(t_mtl *mtl, char *args)
{
	if (!args || !*mtl->name)
		fatal("invalid obj");
	if (sscanf(args, "%d", &mtl->model) < 1)
		fatal("invalid obj");
}
