/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:04:47 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:22:39 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	find_uniform_loc(t_app *app)
{
	app->locs.world = glGetUniformLocation(app->prog, "world");
	app->locs.view = glGetUniformLocation(app->prog, "view");
	app->locs.proj = glGetUniformLocation(app->prog, "proj");
	app->locs.ambient = glGetUniformLocation(app->prog, "ambient");
	app->locs.diffuse = glGetUniformLocation(app->prog, "diffuse");
	app->locs.specular = glGetUniformLocation(app->prog, "specular");
	app->locs.spec_exponent = glGetUniformLocation(app->prog, "spec_exponent");
	app->locs.refract_index = glGetUniformLocation(app->prog, "refract_index");
	app->locs.opacity = glGetUniformLocation(app->prog, "opacity");
	app->locs.model = glGetUniformLocation(app->prog, "model");
	app->locs.tex = glGetUniformLocation(app->prog, "tex");
	app->locs.apply_tex = glGetUniformLocation(app->prog, "apply_tex");
	printf("uniforms used:\n");
	printf("%s", (app->locs.world != -1) ? "world\n" : "");
	printf("%s", (app->locs.view != -1) ? "view\n" : "");
	printf("%s", (app->locs.proj != -1) ? "proj\n" : "");
	printf("%s", (app->locs.ambient != -1) ? "ambient\n" : "");
	printf("%s", (app->locs.diffuse != -1) ? "diffuse\n" : "");
	printf("%s", (app->locs.specular != -1) ? "specular\n" : "");
	printf("%s", (app->locs.spec_exponent != -1) ? "spec_exponent\n" : "");
	printf("%s", (app->locs.refract_index != -1) ? "refract_index\n" : "");
	printf("%s", (app->locs.opacity != -1) ? "opacity\n" : "");
	printf("%s", (app->locs.model != -1) ? "model\n" : "");
	printf("%s", (app->locs.tex != -1) ? "tex\n" : "");
	printf("%s", (app->locs.apply_tex != -1) ? "apply_tex\n" : "");
}

void	set_mtl_uniform(t_app *app, t_mtl *mtl)
{
	glUniform3fv(app->locs.ambient, 1, mtl->amb);
	glUniform3fv(app->locs.diffuse, 1, mtl->dif);
	glUniform3fv(app->locs.specular, 1, mtl->spec);
	glUniform1f(app->locs.spec_exponent, mtl->exp);
	glUniform1f(app->locs.refract_index, mtl->ir);
	glUniform1f(app->locs.spec_exponent, mtl->opac);
	glUniform1f(app->locs.spec_exponent, mtl->model);
}

void	update_uniform(t_app *app)
{
	glUniformMatrix4fv(app->locs.world, 1, GL_FALSE, &app->world[0][0]);
	glUniformMatrix4fv(app->locs.view, 1, GL_FALSE, &app->view[0][0]);
	glUniformMatrix4fv(app->locs.proj, 1, GL_FALSE, &app->proj[0][0]);
	glUniform1i(app->locs.apply_tex, app->tex_mode);
}
