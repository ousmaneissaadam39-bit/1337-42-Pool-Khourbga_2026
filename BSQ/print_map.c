/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		ft_putstr(map->grid[i]);
		ft_putstr("\n");
		++i;
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->rows)
		free(map->grid[i++]);
	free(map->grid);
}
