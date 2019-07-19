/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:20:48 by mchi              #+#    #+#             */
/*   Updated: 2019/07/19 10:48:38 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_resources(t_app *app, int argc, char **argv)
{
	init_buffers(&app->obj);
	init_cam(&app->cam);
	load_program(app);
	if (argc == 1)
		load_obj(&app->obj, "resources/teapot.obj");
	else
		load_obj(&app->obj, argv[1]);
	set_mtl_uniform(app, &app->obj);
}

void	init_glfw(t_app *app)
{
	if (!glfwInit())
		fatal("glfw init failed");
	glfwSetErrorCallback(glfw_error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
	app->wnd = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
	if (!app->wnd)
		fatal("window creation failed");
	glfwMakeContextCurrent(app->wnd);
	glfwSetKeyCallback(app->wnd,
		(void(*)(GLFWwindow*, int, int, int, int))glfw_key_callback);
	glfwSetWindowUserPointer(app->wnd, app);
	if (glewInit() != GLEW_OK)
		fatal("glew init failed");
	printf("OpenGL: %s\n", glGetString(GL_VERSION));
}
