/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:24:32 by mchi              #+#    #+#             */
/*   Updated: 2019/07/17 18:36:25 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	glfw_error_callback(int error, const char *description)
{
	printf("glfw error code: %d\n", error);
	fatal(description);
}

void	glfw_key_callback(GLFWwindow *window, int key, int scancode, int action)
{
	if (action != GLFW_PRESS && action != GLFW_REPEAT)
		return ;
	(void)window;
	(void)scancode;
	(void)key;
}
