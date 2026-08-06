/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*read_fd(int fd)
{
	char	*buf;
	char	*next;
	char	tmp[4096 + 1];
	int		r;

	buf = malloc(1);
	if (!buf)
		exit(1);
	buf[0] = '\0';
	r = read(fd, tmp, 4096);
	while (r > 0)
	{
		tmp[r] = '\0';
		next = ft_strjoin(buf, tmp);
		free(buf);
		buf = next;
		r = read(fd, tmp, 4096);
	}
	if (r < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

/* path == NULL means "read from stdin" */
char	*read_input(char *path)
{
	int		fd;
	char	*content;

	if (!path)
		return (read_fd(0));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_fd(fd);
	close(fd);
	return (content);
}
