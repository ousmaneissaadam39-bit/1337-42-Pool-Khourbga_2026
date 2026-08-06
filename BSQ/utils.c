/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:00:00 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/04 10:00:00 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

/* returns a new malloc'd string, does NOT free s1 or s2 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	res = malloc(len1 + ft_strlen(s2) + 1);
	if (!res)
		exit(1);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int	ft_min3(int a, int b, int c)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	return (a);
}
