/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:38:41 by mchi              #+#    #+#             */
/*   Updated: 2019/07/20 10:43:44 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_log(GLuint to, GLint log_length,
	void (*f)(GLuint, GLsizei, GLsizei *, GLchar *))
{
	char *log;

	if (log_length > 0)
	{
		log = malloc((unsigned long)log_length);
		if (!log)
			fatal("malloc failed");
		(*f)(to, log_length, NULL, log);
		printf("%s", log);
		free(log);
	}
}

void	load_shader(GLuint *shader_id, char *path, GLenum type)
{
	long		size;
	char const	*data;
	GLint		result;
	GLint		log_length;

	*shader_id = glCreateShader(type);
	data = read_file(path, &size);
	glShaderSource(*shader_id, 1, &data, NULL);
	free((void *)data);
	glCompileShader(*shader_id);
	glGetShaderiv(*shader_id, GL_INFO_LOG_LENGTH, &log_length);
	print_log(*shader_id, log_length, glGetShaderInfoLog);
	glGetShaderiv(*shader_id, GL_COMPILE_STATUS, &result);
	if (result != GL_TRUE)
		fatal("shader compile failed");
}

void	load_program(t_app *app)
{
	GLuint	vs;
	GLuint	fs;
	GLint	result;
	GLint	log_length;

	load_shader(&vs, "shaders/vs.glsl", GL_VERTEX_SHADER);
	load_shader(&fs, "shaders/fs.glsl", GL_FRAGMENT_SHADER);
	app->prog = glCreateProgram();
	glAttachShader(app->prog, vs);
	glAttachShader(app->prog, fs);
	glLinkProgram(app->prog);
	glGetProgramiv(app->prog, GL_INFO_LOG_LENGTH, &log_length);
	print_log(app->prog, log_length, glGetProgramInfoLog);
	glGetProgramiv(app->prog, GL_LINK_STATUS, &result);
	if (result != GL_TRUE)
		fatal("shader program build failed");
	glDetachShader(app->prog, vs);
	glDetachShader(app->prog, fs);
	glDeleteShader(vs);
	glDeleteShader(fs);
	glUseProgram(app->prog);
}
