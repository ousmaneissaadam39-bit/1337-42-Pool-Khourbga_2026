/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	alloc_row(t_map *map, char *line, int idx, char **next)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != map->empty && line[j] != map->obstacle)
			return (0);
		++j;
	}
	if (j != map->cols)
		return (0);
	map->grid[idx] = malloc(map->cols + 1);
	if (!map->grid[idx])
		exit(1);
	j = 0;
	while (j < map->cols)
	{
		map->grid[idx][j] = line[j];
		++j;
	}
	map->grid[idx][j] = '\0';
	*next = line + j + (line[j] == '\n');
	return (1);
}

static int	build_grid(char *body, t_map *map)
{
	char	*end;
	int		i;

	end = body;
	while (*end && *end != '\n')
		++end;
	map->cols = end - body;
	if (map->cols == 0)
		return (0);
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		exit(1);
	i = 0;
	while (i < map->rows)
		map->grid[i++] = NULL;
	i = 0;
	while (i < map->rows)
	{
		if (!alloc_row(map, body, i, &body))
			return (0);
		++i;
	}
	return (*body == '\0');
}

int	parse_map(char *content, t_map *map)
{
	char	*body;

	map->grid = NULL;
	if (!parse_header(content, map, &body))
		return (0);
	return (build_grid(body, map));
}
