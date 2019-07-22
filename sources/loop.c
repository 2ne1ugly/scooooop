/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:34:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 10:06:17 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	update(t_app *app)
{
	glfwPollEvents();
	get_world_from_obj(&app->obj, app->world);
	get_view_from_cam(&app->cam, app->view);
	get_proj_from_cam(&app->cam, app->proj);
}

void	render(t_app *app)
{
	glEnable(GL_DEPTH_TEST);
	update_uniform(app);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, app->obj.vtx_buff);
	glBindVertexArray(app->obj.vtx_arr);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawArrays(GL_TRIANGLES, 0, app->obj.vtx_vec->size);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}

void	loop(t_app *app)
{
	while (!glfwWindowShouldClose(app->wnd))
	{
		update(app);
		render(app);
		glFinish();
		glfwSwapBuffers(app->wnd);
	}
	glfwDestroyWindow(app->wnd);
}
