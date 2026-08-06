/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	process(char *path)
{
	char	*content;
	t_map	map;

	content = read_input(path);
	if (!content)
	{
		ft_putstr("map error\n");
		return ;
	}
	if (!parse_map(content, &map))
	{
		free(content);
		free_map(&map);
		ft_putstr("map error\n");
		return ;
	}
	free(content);
	solve_square(&map);
	print_map(&map);
	free_map(&map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		process(NULL);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (i > 1)
			ft_putstr("\n");
		process(argv[i]);
		++i;
	}
	return (0);
}
