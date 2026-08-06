/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:58:37 by isousman          #+#    #+#             */
/*   Updated: 2026/08/05 17:58:42 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	valid_header_chars(char e, char o, char f)
{
	if (e < 32 || e > 126 || o < 32 || o > 126 || f < 32 || f > 126)
		return (0);
	if (e == o || e == f || o == f)
		return (0);
	return (1);
}

static int	parse_rows(char *content, int len, int *rows)
{
	int	i;
	int	digit_len;

	digit_len = len - 3;
	if (digit_len <= 0)
		return (0);
	*rows = 0;
	i = 0;
	while (i < digit_len)
	{
		if (content[i] < '0' || content[i] > '9')
			return (0);
		*rows = *rows * 10 + (content[i] - '0');
		++i;
	}
	if (*rows < 1)
		return (0);
	return (1);
}

int	parse_header(char *content, t_map *map, char **body)
{
	char	*nl;
	int		i;

	nl = content;
	while (*nl && *nl != '\n')
		++nl;
	if (*nl != '\n' || (nl - content) < 4)
		return (0);
	if (!parse_rows(content, nl - content, &map->rows))
		return (0);
	i = (nl - content) - 3;
	if (!valid_header_chars(content[i], content[i + 1], content[i + 2]))
		return (0);
	map->empty = content[i];
	map->obstacle = content[i + 1];
	map->full = content[i + 2];
	*body = nl + 1;
	return (1);
}
