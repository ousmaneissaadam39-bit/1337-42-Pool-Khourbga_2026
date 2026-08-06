/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	cell_size(t_map *map, int *dp, int i, int j)
{
	if (map->grid[i][j] != map->empty)
		return (0);
	if (i == 0 || j == 0)
		return (1);
	return (1 + ft_min3(dp[(i - 1) * map->cols + j],
			dp[i * map->cols + j - 1],
			dp[(i - 1) * map->cols + j - 1]));
}

static void	fill_square(t_map *map, int size, int bi, int bj)
{
	int	i;
	int	j;

	if (size == 0)
		return ;
	i = bi - size + 1;
	while (i <= bi)
	{
		j = bj - size + 1;
		while (j <= bj)
		{
			map->grid[i][j] = map->full;
			++j;
		}
		++i;
	}
}

static void	fill_dp(t_map *map, int *dp, int *best)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			dp[i * map->cols + j] = cell_size(map, dp, i, j);
			if (dp[i * map->cols + j] > best[0])
			{
				best[0] = dp[i * map->cols + j];
				best[1] = i;
				best[2] = j;
			}
			++j;
		}
		++i;
	}
}

void	solve_square(t_map *map)
{
	int	*dp;
	int	best[3];

	dp = malloc(sizeof(int) * map->rows * map->cols);
	if (!dp)
		exit(1);
	best[0] = 0;
	best[1] = 0;
	best[2] = 0;
	fill_dp(map, dp, best);
	fill_square(map, best[0], best[1], best[2]);
	free(dp);
}
