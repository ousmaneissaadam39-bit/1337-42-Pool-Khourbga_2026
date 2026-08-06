/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

/* read_input.c */
char	*read_input(char *path);

/* parse_header.c */
int		parse_header(char *content, t_map *map, char **body);

/* parse_map.c */
int		parse_map(char *content, t_map *map);

/* square.c */
void	solve_square(t_map *map);

/* print_map.c */
void	print_map(t_map *map);
void	free_map(t_map *map);

/* utils.c */
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr(char *s);
int		ft_min3(int a, int b, int c);

#endif
