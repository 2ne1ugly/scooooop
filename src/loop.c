/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:57:29 by mchi              #+#    #+#             */
/*   Updated: 2019/04/09 05:35:31 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	update_wvp(t_app *app)
{
	t_mat	world;
	t_mat	view;
	t_mat	proj;
	t_vec4	test;
	GLuint	mat;

	world = mat_world(&app->obj);
	view = mat_look_at(app->cam.pos, app->cam.ypr.y, app->cam.ypr.x);
	proj = mat_proj(&app->cam);

	test = (t_vec4){-0.5, -0.5, -0.5, 1};
	test = vec4_trans(&world, test);
	test = vec4_trans(&view, test);
	test = vec4_trans(&proj, test);
	//view = mat_identity();
	//proj = mat_identity();
	mat = glGetUniformLocation(app->shader_prog, "world");
	glUniformMatrix4fv(mat, 1, GL_FALSE, &world.v[0]);
	mat = glGetUniformLocation(app->shader_prog, "view");
	glUniformMatrix4fv(mat, 1, GL_FALSE, &view.v[0]);
	mat = glGetUniformLocation(app->shader_prog, "proj");
	glUniformMatrix4fv(mat, 1, GL_FALSE, &proj.v[0]);

///	result = mat_mul(&proj, &view);
//	app->obj.world_view_proj = mat_mul(&result, &world);
}

int		app_loop(void *param)
{
	t_app	*app;

	app = param;
	if (app->update)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(app->shader_prog);
		glBindVertexArray(app->vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, app->ind_buff);
		update_wvp(app);
		glDrawElements(GL_TRIANGLES, app->obj.index_count,
			GL_UNSIGNED_INT, (void*)0);
		mlx_opengl_swap_buffers(app->h_wnd);
	}
	return (0);
}
