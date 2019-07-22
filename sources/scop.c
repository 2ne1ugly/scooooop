/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:16:53 by mchi              #+#    #+#             */
/*   Updated: 2019/07/20 10:44:21 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char		*read_file(const char *path, long *length)
{
	FILE	*f;
	char	*data;
	long	len;

	f = fopen(path, "r");
	if (!f)
		fatal("couldn't open file");
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);
	data = malloc((unsigned long)(len + 1));
	if (!data)
		fatal("malloc fail");
	fread(data, 1, (size_t)len, f);
	data[len] = '\0';
	fclose(f);
	if (length)
		*length = len;
	return (data);
}

int			fatal(const char *msg)
{
	printf("%s\n", msg);
	exit(1);
	return (1);
}

int			main(int argc, char **argv)
{
	static t_app	app;

	init_glfw(&app);
	init_resources(&app, argc, argv);
	loop(&app);
	return (0);
}
