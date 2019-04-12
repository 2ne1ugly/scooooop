/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:28:08 by mchi              #+#    #+#             */
/*   Updated: 2019/04/11 12:55:32 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*read_file(char *path)
{
	struct stat	buf;
	char		*buffer;
	FILE		*fd;

	if (stat(path, &buf) == -1)
		fatal_error("stat failed");
	buffer = malloc(sizeof(char) * (buf.st_size + 1));
	fd = fopen(path, "r");
	fread(buffer, 1, buf.st_size, fd);
	fclose(fd);
	buffer[buf.st_size] = '\0';
	return (buffer);
}

GLuint	load_shader(char *path, int type)
{
	GLuint					id;
	char	const			*source;
	GLint					result;
	int						log_length;
	char					*logs;

	id = glCreateShader(type);
	source = read_file(path);
	printf("Compiling shader : %s\n", path);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);
	result = GL_FALSE;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		logs = malloc(sizeof(char) * (log_length + 1));
		glGetShaderInfoLog(id, log_length, NULL, logs);
		printf("%s\n", logs);
		free(logs);
	}
	return (id);
}

GLuint	link_vs_ps(GLuint vs, GLuint ps)
{
	GLuint	p_id;
	GLint	result;
	int		log_length;
	char	*logs;

	printf("Linking program\n");
	p_id = glCreateProgram();
	glAttachShader(p_id, vs);
	glAttachShader(p_id, ps);
	glLinkProgram(p_id);
	glGetProgramiv(p_id, GL_LINK_STATUS, &result);
	glGetProgramiv(p_id, GL_INFO_LOG_LENGTH, &log_length);
	if (log_length > 0)
	{
		logs = malloc(sizeof(char) * (log_length + 1));
		glGetProgramInfoLog(p_id, log_length, NULL, logs);
		printf("%s\n", logs);
		free(logs);
	}
	glDetachShader(p_id, vs);
	glDetachShader(p_id, ps);
	glDeleteShader(vs);
	glDeleteShader(ps);
	return (p_id);
}
