/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:24:32 by mchi              #+#    #+#             */
/*   Updated: 2019/07/21 17:22:04 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	glfw_error_callback(int error, const char *description)
{
	printf("glfw error code: %d\n", error);
	fatal(description);
}

static void	(*g_keys[500])(t_app *) = {
	[GLFW_KEY_LEFT] = key_left,
	[GLFW_KEY_RIGHT] = key_right,
	[GLFW_KEY_UP] = key_up,
	[GLFW_KEY_DOWN] = key_down,
	[GLFW_KEY_W] = key_w,
	[GLFW_KEY_A] = key_a,
	[GLFW_KEY_S] = key_s,
	[GLFW_KEY_D] = key_d,
	[GLFW_KEY_KP_4] = key_num_4,
	[GLFW_KEY_KP_6] = key_num_6,
	[GLFW_KEY_KP_8] = key_num_8,
	[GLFW_KEY_KP_2] = key_num_2,
	[GLFW_KEY_KP_9] = key_num_9,
	[GLFW_KEY_KP_1] = key_num_1,
	[GLFW_KEY_R] = key_r,
	[GLFW_KEY_1] = key_1
};

void	glfw_key_callback(GLFWwindow *window, int key, int scancode, int action)
{
	t_app	*app;

	(void)scancode;
	if (action != GLFW_PRESS && action != GLFW_REPEAT)
		return ;
	app = glfwGetWindowUserPointer(window);
	if (g_keys[key])
		g_keys[key](app);
}
