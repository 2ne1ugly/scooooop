/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:34:39 by mchi              #+#    #+#             */
/*   Updated: 2019/07/18 20:56:35 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	render(t_app *app)
{
	(void)app;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	loop(t_app *app)
{
	while (!glfwWindowShouldClose(app->wnd))
	{
		glfwPollEvents();
		render(app);
		glFinish();
		glfwSwapBuffers(app->wnd);
	}
	glfwDestroyWindow(app->wnd);
}
