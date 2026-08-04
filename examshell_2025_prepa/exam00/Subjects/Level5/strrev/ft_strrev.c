/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:56:28 by isousman          #+#    #+#             */
/*   Updated: 2026/07/17 11:06:38 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		str[i] = temp;
		str[i] = str[j];
		temp = str[j];
		i++;
		j--;
	}
	return (str);
}

int	main(void)
{
    char str[] = "Hello World!";

    printf("Avant : %s\n", str);   // Hello World!
    ft_strrev(str);
    printf("Après : %s\n", str);   // !dlroW olleH
    return (0);
}
